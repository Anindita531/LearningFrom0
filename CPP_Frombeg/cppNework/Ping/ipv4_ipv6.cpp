#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <icmpapi.h>
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "iphlpapi.lib")

using namespace std;

int main() {
    // Step 1: Initialize Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cout << "WSAStartup failed!" << endl;
        return 1;
    }

    while (true) {
        cout << "Enter hostname or IP to ping (or type 'exit' to quit): ";
        string hostname;
        getline(cin, hostname);

        if (hostname == "exit") break;

        // Step 2: Resolve hostname to IPv4
        addrinfo hints = {};
        hints.ai_family = AF_INET;    // Force IPv4 only
        hints.ai_socktype = SOCK_RAW;

        addrinfo* result = nullptr;
        int res = getaddrinfo(hostname.c_str(), NULL, &hints, &result);
        if (res != 0) {
            cout << "Hostname resolution failed! Error: " << res << endl;
            continue;
        }

        sockaddr_in* ipv4 = (sockaddr_in*)result->ai_addr;
        char ipStr[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(ipv4->sin_addr), ipStr, sizeof(ipStr));

        cout << "Pinging " << hostname << " [" << ipStr << "] ... Press Ctrl+C to stop.\n";

        // Step 3: Create ICMP handle
        HANDLE icmpFile = IcmpCreateFile();
        if (icmpFile == INVALID_HANDLE_VALUE) {
            cout << "IcmpCreateFile failed! Error: " << GetLastError() << endl;
            freeaddrinfo(result);
            continue;
        }

        // Step 4: Prepare send buffer & receive buffer
        char sendData[32] = "Custom Ping Request";
        DWORD replySize = sizeof(ICMP_ECHO_REPLY) + sizeof(sendData);
        void* replyBuffer = (void*)malloc(replySize);

        // Step 5: Send ICMP Echo Request
        DWORD dwRetVal = IcmpSendEcho(
            icmpFile,
            ipv4->sin_addr.S_un.S_addr,
            sendData,
            sizeof(sendData),
            NULL,
            replyBuffer,
            replySize,
            1000
        );

        if (dwRetVal != 0) {
            PICMP_ECHO_REPLY echoReply = (PICMP_ECHO_REPLY)replyBuffer;
            cout << "Reply from " << ipStr
                 << ": bytes=" << echoReply->DataSize
                 << " time=" << echoReply->RoundTripTime << "ms"
                 << " TTL=" << (int)echoReply->Options.Ttl
                 << endl;
        } else {
            cout << "Request timed out! Error: " << GetLastError() << endl;
        }

        free(replyBuffer);
        IcmpCloseHandle(icmpFile);
        freeaddrinfo(result);
    }

    WSACleanup();
    return 0;
}

