 
#include <iostream>
#include <winsock2.h>
#include <thread>
#include <vector>
#include <algorithm>
#include <mutex>    // <-- ADD THIS

#pragma comment(lib, "ws2_32.lib")
using namespace std;

void receiveMessages(SOCKET sock) {
    char buffer[1024];
    while (true) {
        int len = recv(sock, buffer, sizeof(buffer), 0);
        if (len <= 0) break;
        buffer[len] = '\0';
        cout << "[SERVER]: " << buffer << endl;
    }
}

int main() {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    cout << "[CLIENT] Connected to server!" << endl;

    thread recvThread(receiveMessages, sock);

    char buffer[1024];
    while (true) {
        cin.getline(buffer, sizeof(buffer));
        send(sock, buffer, strlen(buffer), 0);
        if (strcmp(buffer, "exit") == 0) break;
    }

    closesocket(sock);
    WSACleanup();
    return 0;
}

