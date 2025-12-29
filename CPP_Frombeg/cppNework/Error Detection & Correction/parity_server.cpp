 #include <iostream>
#include <winsock2.h>
#include <string>
using namespace std;

// Function to check parity (even)
bool checkParity(const string& data) {
    int count = 0;
    for(char c : data) {         // Loop over each character (bit)
        if(c == '1') count++;    // Count number of 1s
    }
    return (count % 2 == 0);     // Even parity returns true
}

int main() {
    WSADATA wsa;
    SOCKET serverSocket;
    struct sockaddr_in server, client;
    char buffer[1024];

    // Step 1: Initialize Winsock
    WSAStartup(MAKEWORD(2, 2), &wsa);

    // Step 2: Create UDP socket (connectionless)
    serverSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if(serverSocket == INVALID_SOCKET) {
        cout << "Socket creation failed!\n";
        return 1;
    }

    // Step 3: Bind socket to IP & port
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;  // Accept connections from any IP
    server.sin_port = htons(9090);        // Port 9090

    if(bind(serverSocket, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) {
        cout << "Bind failed!\n";
        return 1;
    }

    cout << "[SERVER] Waiting for data...\n";

    int clientSize = sizeof(client);
    while(true) {
        memset(buffer, 0, sizeof(buffer)); // Clear buffer

        // Step 4: Receive data from client
        int recvLen = recvfrom(serverSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&client, &clientSize);
        buffer[recvLen] = '\0'; // Null-terminate received string
        cout << "[CLIENT] Data received: " << buffer << endl;

        // Step 5: Check parity
        if(checkParity(buffer))
            cout << "[SERVER] Parity OK, no error detected.\n";
        else
            cout << "[SERVER] Parity error detected!\n";

        // Step 6: Exit condition
        if(string(buffer) == "exit") break;
    }

    closesocket(serverSocket);
    WSACleanup();
    return 0;
}

