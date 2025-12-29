#include <iostream>
#include <winsock2.h>
#include <thread>
#include <vector>
#include <algorithm>
#include <mutex>    // <-- ADD THIS


#pragma comment(lib, "ws2_32.lib")
using namespace std;

vector<SOCKET> clients;
mutex clientsMutex;

void handleClient(SOCKET clientSocket) {
    char buffer[1024];
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int recvLen = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (recvLen <= 0) break;

        buffer[recvLen] = '\0';
        cout << "[CLIENT]: " << buffer << endl;

        // Broadcast to other clients
        lock_guard<mutex> lock(clientsMutex);
        for (auto c : clients) {
            if (c != clientSocket) send(c, buffer, recvLen, 0);
        }

        if (strcmp(buffer, "exit") == 0) break;
    }

    // Remove client
    lock_guard<mutex> lock(clientsMutex);
    clients.erase(std::remove(clients.begin(), clients.end(), clientSocket), clients.end());
    closesocket(clientSocket);
    cout << "[SERVER] Client disconnected." << endl;
}

int main() {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 5);

    cout << "[SERVER] Waiting for clients..." << endl;

    while (true) {
        SOCKET clientSocket = accept(serverSocket, NULL, NULL);
        {
            lock_guard<mutex> lock(clientsMutex);
            clients.push_back(clientSocket);
        }
        cout << "[SERVER] New client connected!" << endl;
        thread t(handleClient, clientSocket);
        t.detach();  // Run thread independently
    }

    closesocket(serverSocket);
    WSACleanup();
    return 0;
}

