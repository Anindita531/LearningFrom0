 #include <iostream>
#include <winsock2.h>
using namespace std;

int main() {
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in server;
    char buffer[1024];

    // Initialize Winsock
    WSAStartup(MAKEWORD(2, 2), &wsa);

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // Server details
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    // Connect to server
    connect(sock, (struct sockaddr*)&server, sizeof(server));
    cout << "[CLIENT] Connected to server!" << endl;

    // Continuous communication
    while (true) {
        cout << "[YOU]: ";
        cin.getline(buffer, sizeof(buffer));
        send(sock, buffer, strlen(buffer), 0);

        if (strcmp(buffer, "exit") == 0) {
            cout << "[CLIENT] Closing connection." << endl;
            break;
        }

        memset(buffer, 0, sizeof(buffer));
        recv(sock, buffer, sizeof(buffer), 0);

        if (strcmp(buffer, "exit") == 0) {
            cout << "[SERVER] Closed connection." << endl;
            break;
        }

        cout << "[SERVER]: " << buffer << endl;
    }

    closesocket(sock);
    WSACleanup();
    return 0;
}

