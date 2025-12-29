#include <iostream>
#include <winsock2.h>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

mutex coutMutex;

void handleClient(SOCKET serverSocket, sockaddr_in client, int clientSize) {
    char buffer[1024];
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int recvLen = recvfrom(serverSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&client, &clientSize);
        if (recvLen == SOCKET_ERROR) break;
        buffer[recvLen] = '\0';

        {
            lock_guard<mutex> lock(coutMutex);
            cout << "[CLIENT " << inet_ntoa(client.sin_addr) << "]: " << buffer << endl;
        }

        if (strcmp(buffer, "exit") == 0) break;

        // Reply to client
        cout << "[YOU]: ";
        cin.getline(buffer, sizeof(buffer));
        sendto(serverSocket, buffer, strlen(buffer), 0, (struct sockaddr*)&client, clientSize);
    }
}

int main() {
    WSADATA wsa;
    SOCKET serverSocket;
    struct sockaddr_in server, client;
    int clientSize = sizeof(client);

    WSAStartup(MAKEWORD(2, 2), &wsa);
    serverSocket = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    bind(serverSocket, (struct sockaddr*)&server, sizeof(server));

    vector<thread> threads;
    cout << "[SERVER] Waiting for clients..." << endl;

    while (true) {
        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));
        int recvLen = recvfrom(serverSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&client, &clientSize);
        if (recvLen == SOCKET_ERROR) continue;
        buffer[recvLen] = '\0';

        cout << "[NEW CLIENT] " << inet_ntoa(client.sin_addr) << " connected." << endl;

        // Create new thread for this client
        threads.push_back(thread(handleClient, serverSocket, client, clientSize));
    }

    for (auto &t : threads) t.join();
    closesocket(serverSocket);
    WSACleanup();
    return 0;
}

