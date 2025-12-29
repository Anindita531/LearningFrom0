#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <icmpapi.h>
#include <vector>
#include <algorithm>
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "iphlpapi.lib")

using namespace std;

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0) {
        cout << "WSAStartup failed!" << endl;
        return 1;
    }

    string hostname;
    cout << "Enter hostname or IP to ping: ";
    getline(cin, hostname);

    // Resolve hostname to IPv4
    addrinfo hints = {};
    hints.ai_family = AF_INET; // Force IPv4
    addrinfo* result = nullptr;
    if (getaddrinfo(hostname.c_str(), NULL, &hints, &result) != 0) {
        cout << "Hostname resolution failed!" << endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in* ipv4 = (sockaddr_in*)result->ai_addr;
    char ipStr[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(ipv4->sin_addr), ipStr, sizeof(ipStr));

    cout << "Pinging " << hostname << " [" << ipStr << "] with 32 bytes of data:\n";

    HANDLE icmpFile = IcmpCreateFile();
    if (icmpFile == INVALID_HANDLE_VALUE) {
        cout << "IcmpCreateFile failed! Error: " << GetLastError() << endl;
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    char sendData[32] = "Custom Ping Request";
    DWORD replySize = sizeof(ICMP_ECHO_REPLY) + sizeof(sendData);
    void* replyBuffer = malloc(replySize);

    int sent = 0, received = 0;
    vector<DWORD> times;

    for (int i = 0; i < 4; i++) { // Send 4 pings
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

        sent++;
        if (dwRetVal != 0) {
            PICMP_ECHO_REPLY echoReply = (PICMP_ECHO_REPLY)replyBuffer;
            cout << "Reply from " << ipStr
                 << ": bytes=" << echoReply->DataSize
                 << " time=" << echoReply->RoundTripTime << "ms"
                 << " TTL=" << (int)echoReply->Options.Ttl << endl;
            times.push_back(echoReply->RoundTripTime);
            received++;
        } else {
            cout << "Request timed out." << endl;
        }

        Sleep(1000); // 1-second interval
    }

    // Statistics
    cout << "\nPing statistics for " << ipStr << ":\n";
    cout << "    Packets: Sent = " << sent
         << ", Received = " << received
         << ", Lost = " << (sent - received)
         << " (" << ((sent - received)*100/sent) << "% loss)\n";

    if (!times.empty()) {
        DWORD minTime = *min_element(times.begin(), times.end());
        DWORD maxTime = *max_element(times.begin(), times.end());
        DWORD avgTime = 0;
        for (auto t : times) avgTime += t;
        avgTime /= times.size();
        cout << "Approximate round trip times in milli-seconds:\n";
        cout << "    Minimum = " << minTime
             << "ms, Maximum = " << maxTime
             << "ms, Average = " << avgTime << "ms\n";
    }

    free(replyBuffer);
    IcmpCloseHandle(icmpFile);
    freeaddrinfo(result);
    WSACleanup();

    return 0;
}

