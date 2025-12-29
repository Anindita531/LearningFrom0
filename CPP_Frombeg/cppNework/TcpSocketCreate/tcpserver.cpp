#include <iostream>
#include <winsock2.h>
using namespace std;

int main() {
    WSADATA wsa;
    SOCKET serverSocket, clientSocket;
    struct sockaddr_in server, client;
    char buffer[1024];

    cout << "Initializing Winsock..." << endl;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        cout << "Socket creation failed!" << endl;
        return 1;
    }

    // Prepare sockaddr_in
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    // Bind
    bind(serverSocket, (struct sockaddr*)&server, sizeof(server));

    // Listen
    listen(serverSocket, 3);

    cout << "Waiting for client..." << endl;
    int clientSize = sizeof(client);
    clientSocket = accept(serverSocket, (struct sockaddr*)&client, &clientSize);
    cout << "Client connected!" << endl;

    // Receive message
    recv(clientSocket, buffer, sizeof(buffer), 0);
    cout << "Client says: " << buffer << endl;

    // Send response
    char reply[] = "Hello from Server!";
    send(clientSocket, reply, strlen(reply), 0);

    // Close sockets
    closesocket(serverSocket);
    closesocket(clientSocket);
    WSACleanup();

    return 0;
}

