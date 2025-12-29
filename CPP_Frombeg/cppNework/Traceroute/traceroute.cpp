#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <icmpapi.h>
#include <chrono>

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "iphlpapi.lib")

using namespace std;
using namespace std::chrono;

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0) {
        cout << "WSAStartup failed!" << endl;
        return 1;
    }

    string hostname;
    cout << "Enter hostname or IP to traceroute: ";
    getline(cin, hostname);

    // Resolve hostname to IPv4
    addrinfo hints = {};
    hints.ai_family = AF_INET; // IPv4
    addrinfo* result = nullptr;
    if (getaddrinfo(hostname.c_str(), NULL, &hints, &result) != 0) {
        cout << "Hostname resolution failed!" << endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in* destAddr = (sockaddr_in*)result->ai_addr;
    char destIP[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(destAddr->sin_addr), destIP, sizeof(destIP));
    cout << "Traceroute to " << hostname << " [" << destIP << "]\n\n";

    HANDLE icmpFile = IcmpCreateFile();
    if (icmpFile == INVALID_HANDLE_VALUE) {
        cout << "IcmpCreateFile failed! Error: " << GetLastError() << endl;
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    char sendData[32] = "Traceroute packet";
    DWORD replySize = sizeof(ICMP_ECHO_REPLY) + sizeof(sendData);
    void* replyBuffer = malloc(replySize);

    const int MAX_HOPS = 30;
    const int TIMEOUT = 1000; // 1 second per hop
    bool reached = false;

    for (int ttl = 1; ttl <= MAX_HOPS && !reached; ttl++) {
        // Set TTL for each hop 

        auto start = high_resolution_clock::now();
        DWORD dwRetVal = IcmpSendEcho(
            icmpFile,
            destAddr->sin_addr.S_un.S_addr,
            sendData,
            sizeof(sendData),
            NULL,
            replyBuffer,
            replySize,
            TIMEOUT
        );
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start).count();

        cout << ttl << "\t";

        if (dwRetVal != 0) {
            PICMP_ECHO_REPLY echoReply = (PICMP_ECHO_REPLY)replyBuffer;
            char hopIP[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &(echoReply->Address), hopIP, sizeof(hopIP));

            cout << hopIP << "\t" << duration << "ms\n";

            if (echoReply->Address == destAddr->sin_addr.S_un.S_addr)
                reached = true;
        } else {
            cout << "*\n"; // Timeout or unreachable
        }
    }

    free(replyBuffer);
    IcmpCloseHandle(icmpFile);
    freeaddrinfo(result);
    WSACleanup();

    return 0;
}

