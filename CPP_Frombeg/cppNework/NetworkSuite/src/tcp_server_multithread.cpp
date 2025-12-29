#include <algorithm> // required for std::remove
#include <vector>
#include <winsock2.h>
#include <thread>
#include <mutex>
#include <iostream>
using namespace std;

vector<SOCKET> clients;
mutex clientsMutex;

void handleClient(SOCKET clientSocket){
    char buffer[1024];
    while(true){
        int recvLen = recv(clientSocket, buffer, sizeof(buffer), 0);
        if(recvLen <= 0) break;
        buffer[recvLen] = '\0';
        cout << "[CLIENT]: " << buffer << endl;

        cout << "[YOU]: ";
        cin.getline(buffer, sizeof(buffer));
        send(clientSocket, buffer, strlen(buffer), 0);
    }
    closesocket(clientSocket);
    lock_guard<mutex> lock(clientsMutex);
    clients.erase(remove(clients.begin(), clients.end(), clientSocket), clients.end());
}

int main(){
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    bind(serverSocket, (sockaddr*)&server, sizeof(server));
    listen(serverSocket, 5);

    cout << "[TCP SERVER] Waiting for clients...\n";

    while(true){
        sockaddr_in client;
        int clientSize = sizeof(client);
        SOCKET clientSocket = accept(serverSocket, (sockaddr*)&client, &clientSize);

        lock_guard<mutex> lock(clientsMutex);
        clients.push_back(clientSocket);

        thread(handleClient, clientSocket).detach();
    }

    closesocket(serverSocket);
    WSACleanup();
    return 0;
}

