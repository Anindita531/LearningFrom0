#include <iostream>
#include <winsock2.h>
#include <thread>
#include <vector>
#include <string>
#include <mutex>
#include <algorithm>  // Add this at the top

#pragma comment(lib, "ws2_32.lib")
using namespace std;

vector<SOCKET> clients;        // List of connected clients
mutex clientsMutex;            // Protect the list

void handleClient(SOCKET clientSocket) {
    char buffer[1024];
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived <= 0) break; // Client disconnected

        // Broadcast to all clients
        lock_guard<mutex> lock(clientsMutex);
        for (SOCKET c : clients) {
            if (c != clientSocket) {
                send(c, buffer, bytesReceived, 0);
            }
        }
        cout << "[CLIENT]: " << buffer << endl;
    }

    // Remove client from list
    lock_guard<mutex> lock(clientsMutex);
    clients.erase(remove(clients.begin(), clients.end(), clientSocket), clients.end());
    closesocket(clientSocket);
    cout << "Client disconnected." << endl;
}

int main() {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(8080);

    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 5);
    cout << "[SERVER] Listening on port 8080..." << endl;

    while (true) {
        SOCKET clientSocket = accept(serverSocket, NULL, NULL);
        cout << "New client connected!" << endl;

        lock_guard<mutex> lock(clientsMutex);
        clients.push_back(clientSocket);

        thread t(handleClient, clientSocket);
        t.detach(); // Run thread independently
    }

    closesocket(serverSocket);
    WSACleanup();
    return 0;
}

