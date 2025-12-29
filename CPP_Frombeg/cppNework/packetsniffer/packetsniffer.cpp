#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib,"ws2_32.lib")
using namespace std;

void printPacketInfo(char* buffer, int size) {
    struct iphdr {
        unsigned char ihl:4;
        unsigned char version:4;
        unsigned char tos;
        unsigned short tot_len;
        unsigned short id;
        unsigned short frag_off;
        unsigned char ttl;
        unsigned char protocol;
        unsigned short check;
        unsigned int saddr;
        unsigned int daddr;
    };
    
    iphdr *ip = (iphdr*)buffer;
    cout << "Protocol: " << (int)ip->protocol
         << " | Source IP: " << inet_ntoa(*(in_addr*)&ip->saddr)
         << " | Dest IP: " << inet_ntoa(*(in_addr*)&ip->daddr)
         << endl;
}

int main() {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);
    
    SOCKET sniffer = socket(AF_INET, SOCK_RAW, IPPROTO_IP);
    if(sniffer == INVALID_SOCKET) {
        cout << "Raw socket creation failed!" << endl;
        return 1;
    }

    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change to your adapter IP

    if(bind(sniffer, (sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR) {
        cout << "Bind failed!" << endl;
        return 1;
    }

    char buffer[65536];
    cout << "[*] Packet Sniffer Started..." << endl;
    while(true) {
        int size = recv(sniffer, buffer, sizeof(buffer), 0);
        if(size > 0) printPacketInfo(buffer, size);
    }

    closesocket(sniffer);
    WSACleanup();
    return 0;
}

