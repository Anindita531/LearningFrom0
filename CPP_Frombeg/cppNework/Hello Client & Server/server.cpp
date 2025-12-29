#include <iostream>
#include <winsock2.h>
using namespace std;

int main() {
    WSADATA wsa;
    SOCKET serverSocket, clientSocket;
    struct sockaddr_in server, client;
    char buffer[1024];

    // Step 1: Initialize Winsock
    cout << "Initializing Winsock..." << endl;
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        cout << "Failed. Error Code: " << WSAGetLastError();
        return 1;
    }

    // Step 2: Create a socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        cout << "Socket creation failed!";
        return 1;
    }

    // Step 3: Bind socket to port 8080
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);
    bind(serverSocket, (struct sockaddr*)&server, sizeof(server));

    // Step 4: Listen for clients
    listen(serverSocket, 3);
    cout << "Server started... Waiting for client..." << endl;

    // Step 5: Accept client connection
    int clientSize = sizeof(client);
    clientSocket = accept(serverSocket, (struct sockaddr*)&client, &clientSize);
    cout << "Client connected!" << endl;

    // Step 6: Receive message from client
    recv(clientSocket, buffer, sizeof(buffer), 0);
    cout << "Client says: " << buffer << endl;

    // Step 7: Send response to client
    char reply[] = "Hello Client! Message received.";
    send(clientSocket, reply, strlen(reply), 0);

    // Step 8: Close sockets
    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}

