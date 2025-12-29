#include <iostream>
#include <winsock2.h>
#include <thread>
using namespace std;

void receiveMessages(SOCKET sock) {
    char buffer[1024];
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int bytesReceived = recv(sock, buffer, sizeof(buffer), 0);
        if (bytesReceived <= 0) break;
        cout << "[SERVER]: " << buffer << endl;
    }
}

int main() {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (sockaddr*)&serverAddr, sizeof(serverAddr)) != 0) {
        return 1;
    }

    cout << "[CLIENT] Connected to server!" << endl;

    // Start thread for receiving messages
    thread t(receiveMessages, sock);
    t.detach();

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

