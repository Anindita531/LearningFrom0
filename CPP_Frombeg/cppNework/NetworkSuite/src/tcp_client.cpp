#include <iostream>
#include <winsock2.h>
using namespace std;

int main(){
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(sock, (sockaddr*)&server, sizeof(server)) < 0){
        cout << "Connection failed\n"; return 1;
    }

    char buffer[1024];
    cout << "[TCP CLIENT] Connected to server!\n";

    while(true){
        cout << "[YOU]: ";
        cin.getline(buffer, sizeof(buffer));
        send(sock, buffer, strlen(buffer), 0);
        if(strcmp(buffer,"exit") == 0) break;

        memset(buffer,0,sizeof(buffer));
        int recvLen = recv(sock, buffer, sizeof(buffer), 0);
        buffer[recvLen] = '\0';
        cout << "[SERVER]: " << buffer << endl;
    }

    closesocket(sock);
    WSACleanup();
    return 0;
}

