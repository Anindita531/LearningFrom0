#include <iostream>
#include <algorithm>  // For std::reverse
#include <string>     // For std::string

#include <winsock2.h> // Windows Socket API
#pragma comment(lib, "ws2_32.lib") // Link Winsock library
using namespace std;

std::string toUppercase(const std::string& input) {
    std::string result = input;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::toupper(c); });
    return result;
}
 int main() {
    WSADATA wsa; //  structure for Winsock info
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) { 
        cout << "Winsock initialization failed!" << endl;
        return 1;
    }

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        cout << "Socket creation failed!" << endl;
        return 1;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET; // IPv4
    serverAddr.sin_port = htons(8080); // Port 8080
    serverAddr.sin_addr.s_addr = INADDR_ANY; // Accept any IP

    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cout << "Bind failed!" << endl;
        return 1;
    }

    if (listen(serverSocket, 5) == SOCKET_ERROR) {
        cout << "Listen failed!" << endl;
        return 1;
    }

    cout << "[SERVER] Waiting for client..." << endl;

    sockaddr_in clientAddr;
    int clientSize = sizeof(clientAddr);
    SOCKET clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientSize);
    if (clientSocket == INVALID_SOCKET) {
        cout << "Accept failed!" << endl;
        return 1;
    }

    char buffer[1024];
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived <= 0) break;

        cout << "[CLIENT] " << buffer << endl;

        // uppercse the string
       
		std::string str(buffer);           // Convert char[] to std::string
    std::string upper = toUppercase(str);  // Convert to uppercase
        send(clientSocket, upper.c_str(), str.length(), 0);
    }

    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();
    return 0;
}

