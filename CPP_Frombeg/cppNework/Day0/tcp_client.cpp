#include <iostream>
#include <winsock2.h> // Windows Socket API
#pragma comment(lib, "ws2_32.lib") // Link Winsock library
using namespace std;


int main() {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost

    if (connect(sock, (sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        cout << "Connection failed!" << endl;
        return 1;
    }

    cout << "[CLIENT] Connected to server!" << endl;
    char buffer[1024];

    while (true) {
        cout << "[YOU]: ";
        cin.getline(buffer, sizeof(buffer));
        send(sock, buffer, strlen(buffer), 0);

        if (strcmp(buffer, "exit") == 0) break;

        memset(buffer, 0, sizeof(buffer));
        recv(sock, buffer, sizeof(buffer), 0);
        cout << "[SERVER] Reversed: " << buffer << endl;
    }

    closesocket(sock);
    WSACleanup();
    return 0;
}

