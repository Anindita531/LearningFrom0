 #include <iostream>
#include <winsock2.h>
using namespace std;

int main() {
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in server;
    char buffer[1024];

    WSAStartup(MAKEWORD(2, 2), &wsa);
    sock = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    connect(sock, (struct sockaddr*)&server, sizeof(server));

    cout << "Enter message: ";
    cin.getline(buffer, sizeof(buffer));
    send(sock, buffer, strlen(buffer), 0);

    recv(sock, buffer, sizeof(buffer), 0);
    cout << "Server reply: " << buffer << endl;

    closesocket(sock);
    WSACleanup();
    return 0;
}

