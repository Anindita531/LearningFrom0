// day1_socket_create_windows.cpp
#include <iostream>
#include <winsock2.h>  // Use Windows socket library
#pragma comment(lib, "ws2_32.lib")  // Auto link in Visual Studio
using namespace std;
int main() {
    WSADATA wsaData;
 
    // Step 1: Initialize Winsock
    int wsaInit = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (wsaInit != 0) {
        cerr << "WSAStartup failed. Error Code: " << wsaInit << endl;
        return 1;
    }

    // Step 2: Create Socket
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        cerr << "Socket creation failed. Error Code: " << WSAGetLastError() << endl;
        WSACleanup();
        return 1;
    }

   cout << "? Socket created successfully! Socket FD: " << sock << endl;

    // Step 3: Close socket and cleanup
    closesocket(sock);
    WSACleanup();
    return 0;
}

