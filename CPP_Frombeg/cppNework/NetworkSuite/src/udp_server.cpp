#include <iostream>
#include <winsock2.h>
using namespace std;

int main() {
    WSADATA wsa;
    SOCKET serverSocket;
    sockaddr_in server, client;
    char buffer[1024];

    WSAStartup(MAKEWORD(2,2), &wsa);
    serverSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if(serverSocket == INVALID_SOCKET) { cout << "Socket creation failed\n"; return 1; }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    if(bind(serverSocket, (sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) { cout << "Bind failed\n"; return 1; }

    cout << "[SERVER] Waiting for messages...\n";
    int clientSize = sizeof(client);
    while(true){
        memset(buffer, 0, sizeof(buffer));
        int recvLen = recvfrom(serverSocket, buffer, sizeof(buffer), 0, (sockaddr*)&client, &clientSize);
        buffer[recvLen] = '\0';
        cout << "[CLIENT]: " << buffer << endl;

        if(strcmp(buffer, "exit") == 0) break;

        cout << "[YOU]: ";
        cin.getline(buffer, sizeof(buffer));
        sendto(serverSocket, buffer, strlen(buffer), 0, (sockaddr*)&client, clientSize);
    }

    closesocket(serverSocket);
    WSACleanup();
    return 0;
}

