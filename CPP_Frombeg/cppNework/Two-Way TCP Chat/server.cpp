#include <iostream>
#include <winsock2.h>
using namespace std;

int main() {
    WSADATA wsa;
    SOCKET serverSocket, clientSocket;
    struct sockaddr_in server, client;
    char buffer[1024];

    // Initialize Winsock
    WSAStartup(MAKEWORD(2, 2), &wsa);

    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    // Server address
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    // Bind
    bind(serverSocket, (struct sockaddr*)&server, sizeof(server));

    // Listen for client
    listen(serverSocket, 3);
    cout << "[SERVER] Waiting for client..." << endl;

    int clientSize = sizeof(client);
    clientSocket = accept(serverSocket, (struct sockaddr*)&client, &clientSize);
    cout << "[SERVER] Client connected!" << endl;

    // Continuous communication
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        recv(clientSocket, buffer, sizeof(buffer), 0);

        if (strcmp(buffer, "exit") == 0) {
            cout << "[SERVER] Client disconnected." << endl;
            break;
        }

        cout << "[CLIENT]: " << buffer << endl;

        cout << "[YOU]: ";
        cin.getline(buffer, sizeof(buffer));
        send(clientSocket, buffer, strlen(buffer), 0);

        if (strcmp(buffer, "exit") == 0) {
            cout << "[SERVER] Closing connection." << endl;
            break;
        }
    }

    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();
    return 0;
}

