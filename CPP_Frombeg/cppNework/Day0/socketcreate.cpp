#include <iostream>
#include <winsock2.h>
using namespace std;

int main() {
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        cout << "Winsock initialization failed!" << endl;
        return 1;
    }

    SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == INVALID_SOCKET) {
        cout << "Socket creation failed!" << endl;
        WSACleanup();
        return 1;
    }

    cout << "Socket created successfully!" << endl;

    // Cleanup
    closesocket(s);
    WSACleanup();
    return 0;
}

