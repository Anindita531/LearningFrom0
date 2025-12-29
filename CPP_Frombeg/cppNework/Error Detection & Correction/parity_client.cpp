#include <iostream>
#include <winsock2.h>
#include <string>
using namespace std;

// Function to calculate parity (even)
char calculateParity(const string& data) {
    int count = 0;
    for(char c : data) if(c == '1') count++;
    return (count % 2 == 0) ? '0' : '1';
}

int main() {
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in server;
    char buffer[1024];

    // Step 1: Initialize Winsock
    WSAStartup(MAKEWORD(2,2), &wsa);

    // Step 2: Create UDP socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock == INVALID_SOCKET) {
        cout << "Socket creation failed!\n";
        return 1;
    }

    // Step 3: Server details
    server.sin_family = AF_INET;
    server.sin_port = htons(9090);
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost

    int serverSize = sizeof(server);
    cout << "[CLIENT] Connected to server!\n";

    while(true) {
        cout << "[YOU] Enter 7-bit data: ";
        string data;
        cin >> data;

        // Step 4: Calculate parity and append
        char parity = calculateParity(data);
        string toSend = data + parity;

        // Step 5: Send data to server
        sendto(sock, toSend.c_str(), toSend.size(), 0, (struct sockaddr*)&server, serverSize);

        // Exit condition
        if(data == "exit") break;
    }

    closesocket(sock);
    WSACleanup();
    return 0;
}

