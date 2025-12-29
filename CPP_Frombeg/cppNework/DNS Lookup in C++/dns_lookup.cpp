#include <iostream>
#include <winsock2.h>
using namespace std;

int main() {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    char domain[100];
    cout << "Enter domain name: ";
    cin >> domain;

    struct hostent *host = gethostbyname(domain);
    if (host == NULL) {
        cout << "DNS Lookup failed!" << endl;
        return 1;
    }

    cout << "IP Address: " << inet_ntoa(*(struct in_addr*)host->h_addr) << endl;

    WSACleanup();
    return 0;
}

