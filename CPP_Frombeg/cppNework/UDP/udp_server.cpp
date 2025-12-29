#include <iostream>
#include <winsock2.h>
using namespace std;

int main() {
    WSADATA wsa;
    SOCKET serverSocket;
    struct sockaddr_in server, client;
    char buffer[1024];

    // Initialize Winsock
    WSAStartup(MAKEWORD(2, 2), &wsa);

    // Create UDP socket
    serverSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        cout << "Socket creation failed!" << endl;
        return 1;
    }

    // Server details
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    // Bind socket
    if (bind(serverSocket, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) {
        cout << "Bind failed!" << endl;
        return 1;
    }

    cout << "[SERVER] Waiting for messages..." << endl;

    // Receive & send continuously
    int clientSize = sizeof(client);
    while (true) {
        memset(buffer, 0, sizeof(buffer));

        // Receive message
        int recvLen = recvfrom(serverSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&client, &clientSize);
        buffer[recvLen] = '\0';
        cout << "[CLIENT]: " << buffer << endl;

        // Exit condition
        if (strcmp(buffer, "exit") == 0) {
            cout << "[SERVER] Client disconnected!" << endl;
            break;
        }

        // Reply to client
        cout << "[YOU]: ";
        cin.getline(buffer, sizeof(buffer));
        sendto(serverSocket, buffer, strlen(buffer), 0, (struct sockaddr*)&client, clientSize);
    }

    closesocket(serverSocket);
    WSACleanup();
    return 0;
}

