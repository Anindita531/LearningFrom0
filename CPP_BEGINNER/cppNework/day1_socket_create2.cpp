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
	 SOCKET sock1 = socket(AF_INET, SOCK_STREAM, 0);
	SOCKET sock2 = socket(AF_INET, SOCK_DGRAM, 0);

    if (sock1 == INVALID_SOCKET && sock2 == INVALID_SOCKET) {
        cerr << "Socket creation failed. Error Code: " << WSAGetLastError() << endl;
        WSACleanup();
        return 1;
    }
std::cout << "Socket created successfully!  TCP socket FD: " << sock1 << std::endl;
std::cout << "Socket created successfully! UDP socket FD: " << sock2 << std::endl;


    // Step 3: Close socket and cleanup
    closesocket(sock1);
      closesocket(sock2);
    WSACleanup();
    return 0;
}

