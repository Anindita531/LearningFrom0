#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <icmpapi.h>

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "iphlpapi.lib")

using namespace std;

int main() {
    // Initialize Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "WSAStartup failed!" << endl;
        return 1;
    }

    string hostname;
    cout << "Enter hostname or IP to ping (or type 'exit' to quit): ";

    while (getline(cin, hostname)) {
        if (hostname == "exit")
            break;

        // Resolve hostname to IPv4 address
        addrinfo hints = {}, *res = nullptr;
        hints.ai_family = AF_INET; // Force IPv4
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_protocol = IPPROTO_TCP;

        if (getaddrinfo(hostname.c_str(), nullptr, &hints, &res) != 0) {
            cerr << "Unable to resolve hostname!" << endl;
            cout << "\nEnter hostname or IP to ping (or type 'exit' to quit): ";
            continue;
        }

        sockaddr_in* ipv4 = (sockaddr_in*)res->ai_addr;
        char ipStr[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(ipv4->sin_addr), ipStr, sizeof(ipStr));

        cout << "\nPinging " << hostname << " [" << ipStr << "]..." << endl;

        // Create ICMP handle
        HANDLE hIcmpFile = IcmpCreateFile();
        if (hIcmpFile == INVALID_HANDLE_VALUE) {
            cerr << "IcmpCreateFile failed. Error: " << GetLastError() << endl;
            freeaddrinfo(res);
            break;
        }

        // Prepare send data
        char sendData[32] = "ICMP Ping Test";
        DWORD replySize = sizeof(ICMP_ECHO_REPLY) + sizeof(sendData);
        LPVOID replyBuffer = malloc(replySize);

        DWORD retVal = IcmpSendEcho(
            hIcmpFile,
            ipv4->sin_addr.S_un.S_addr,
            sendData,
            sizeof(sendData),
            NULL,
            replyBuffer,
            replySize,
            1000 // 1 second timeout
        );

        if (retVal != 0) {
            PICMP_ECHO_REPLY pEchoReply = (PICMP_ECHO_REPLY)replyBuffer;
            cout << "Reply from " << ipStr
                 << ": bytes=" << pEchoReply->DataSize
                 << " time=" << pEchoReply->RoundTripTime << "ms"
                 << " TTL=" << (int)pEchoReply->Options.Ttl << endl;
        } else {
            cerr << "Request failed! Error: " << GetLastError() << endl;
        }

        free(replyBuffer);
        IcmpCloseHandle(hIcmpFile);
        freeaddrinfo(res);

        cout << "\nEnter hostname or IP to ping (or type 'exit' to quit): ";
    }

    WSACleanup();
    return 0;
}

