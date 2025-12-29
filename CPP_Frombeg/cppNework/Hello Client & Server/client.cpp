#include <iostream>
#include <winsock2.h>
using namespace std;

int main() {
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in server;
    char buffer[1024];

    // Step 1: Initialize Winsock
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        cout << "Failed to initialize!";
        return 1;
    }

    // Step 2: Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        cout << "Socket creation failed!";
        return 1;
    }

    // Step 3: Set server details
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    // Step 4: Connect to server
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        cout << "Connection failed!";
        return 1;
    }

    // Step 5: Send message to server
    cout << "Enter message: ";
    cin.getline(buffer, sizeof(buffer));
    send(sock, buffer, strlen(buffer), 0);

    // Step 6: Receive reply
    recv(sock, buffer, sizeof(buffer), 0);
    cout << "Server reply: " << buffer << endl;

    closesocket(sock);
    WSACleanup();
    return 0;
}

