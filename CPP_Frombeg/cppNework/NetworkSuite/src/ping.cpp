#include <iostream>
#include <winsock2.h>
#include <iphlpapi.h>
#include <icmpapi.h>
using namespace std;

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    char host[100];
    cout << "Enter hostname or IP to ping: ";
    cin >> host;

    HANDLE icmpFile = IcmpCreateFile();
    if (icmpFile == INVALID_HANDLE_VALUE) {
        cout << "Unable to open ICMP handle." << endl;
        return 1;
    }

    IPAddr ipAddr = inet_addr(host);
    if (ipAddr == INADDR_NONE) {
        cout << "Resolving hostname..." << endl;
        struct hostent *remoteHost = gethostbyname(host);
        if (!remoteHost) {
            cout << "Unable to resolve hostname!" << endl;
            return 1;
        }
        ipAddr = *((unsigned long*)remoteHost->h_addr);
    }

    char sendData[32] = "NetworkSuite Ping Test";
    DWORD replySize = sizeof(ICMP_ECHO_REPLY) + sizeof(sendData);
    void* replyBuffer = malloc(replySize);

    DWORD ret = IcmpSendEcho(icmpFile, ipAddr, sendData, sizeof(sendData), NULL, replyBuffer, replySize, 1000);
    if (ret) {
        ICMP_ECHO_REPLY *reply = (ICMP_ECHO_REPLY*)replyBuffer;
        cout << "Reply from " << inet_ntoa(*(in_addr*)&reply->Address) 
             << ": bytes=" << reply->DataSize 
             << " time=" << reply->RoundTripTime 
             << "ms TTL=" << (int)reply->Options.Ttl << endl;
    } else {
        cout << "Ping failed!" << endl;
    }

    free(replyBuffer);
    IcmpCloseHandle(icmpFile);
    WSACleanup();
    return 0;
}

