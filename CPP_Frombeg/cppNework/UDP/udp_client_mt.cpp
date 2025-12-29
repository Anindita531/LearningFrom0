#include <iostream>
#include <winsock2.h>
using namespace std;

int main() {
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in server;
    int serverSize = sizeof(server);
    char buffer[1024];

    WSAStartup(MAKEWORD(2,2), &wsa);
    sock = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    cout << "[CLIENT] Connected to server!" << endl;

    while (true) {
        cout << "[YOU]: ";
        cin.getline(buffer, sizeof(buffer));
        sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr*)&server, serverSize);
        if (strcmp(buffer, "exit") == 0) break;

        memset(buffer, 0, sizeof(buffer));
        int recvLen = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&server, &serverSize);
        buffer[recvLen] = '\0';
        cout << "[SERVER]: " << buffer << endl;
    }

    closesocket(sock);
    WSACleanup();
    return 0;
}

