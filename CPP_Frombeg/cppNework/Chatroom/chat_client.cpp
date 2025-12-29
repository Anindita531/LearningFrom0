#include <iostream>
#include <winsock2.h>
using namespace std;

#define PORT 8080

int main() {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(sock, (sockaddr*)&server, sizeof(server)) < 0) {
        cerr << "Connection failed!" << endl;
        return 1;
    }

    cout << "[CLIENT] Connected to chatroom!" << endl;

    while(true) {
        fd_set readSet;
        FD_ZERO(&readSet);
        FD_SET(sock, &readSet);
        FD_SET(0, &readSet); // stdin

        int n = select(sock + 1, &readSet, nullptr, nullptr, nullptr);
        if(FD_ISSET(sock, &readSet)) {
            char buffer[1024];
            int len = recv(sock, buffer, sizeof(buffer), 0);
            if(len <= 0) {
                cout << "[CLIENT] Server disconnected!" << endl;
                break;
            }
            buffer[len] = '\0';
            cout << "[SERVER]: " << buffer << endl;
        }

        if(FD_ISSET(0, &readSet)) {
            string msg;
            getline(cin, msg);
            send(sock, msg.c_str(), msg.length(), 0);
        }
    }

    closesocket(sock);
    WSACleanup();
    return 0;
}

