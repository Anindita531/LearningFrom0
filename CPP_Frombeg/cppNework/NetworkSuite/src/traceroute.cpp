#include <iostream>
#include <winsock2.h>
#include <iphlpapi.h>
#include <icmpapi.h>
using namespace std;

#pragma comment(lib,"iphlpapi.lib")
#pragma comment(lib,"ws2_32.lib")

int main(){
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);

    char host[100];
    cout << "Enter hostname or IP: ";
    cin >> host;

    HANDLE icmpFile = IcmpCreateFile();
    if(icmpFile==INVALID_HANDLE_VALUE){ cout<<"Cannot open ICMP handle\n"; return 1; }

    IPAddr ipAddr = inet_addr(host);
    if(ipAddr==INADDR_NONE){
        struct hostent *remote = gethostbyname(host);
        if(!remote){ cout<<"Cannot resolve host\n"; return 1; }
        ipAddr = *((unsigned long*)remote->h_addr);
    }

    cout << "Traceroute not fully implemented in simple C++ (needs raw sockets/TTL adjustment).\n";
    cout << "Use ping.exe or external tools for testing.\n";

    IcmpCloseHandle(icmpFile);
    WSACleanup();
    return 0;
}

