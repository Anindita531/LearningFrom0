#include <iostream>
#include <winsock2.h>
#include <vector>
#include <algorithm>

using namespace std;

#define PORT 8080
#define MAX_CLIENTS 10

int main() {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);

    SOCKET server = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    bind(server, (sockaddr*)&addr, sizeof(addr));
    listen(server, MAX_CLIENTS);

    cout << "[SERVER] Chatroom started on port " << PORT << endl;

    fd_set masterSet, readSet;
    FD_ZERO(&masterSet);
    FD_SET(server, &masterSet);
    int maxSD = server;

    vector<SOCKET> clients;

    while(true) {
        readSet = masterSet;
        if(select(maxSD + 1, &readSet, nullptr, nullptr, nullptr) < 0) {
            cerr << "Select error!" << endl;
            break;
        }

        for(int i=0; i<=maxSD; ++i) {
            if(FD_ISSET(i, &readSet)) {
                if(i == server) {
                    // New client
                    SOCKET clientSock = accept(server, nullptr, nullptr);
                    clients.push_back(clientSock);
                    FD_SET(clientSock, &masterSet);
                    if(clientSock > maxSD) maxSD = clientSock;
                    cout << "[SERVER] New client connected: " << clientSock << endl;
                } else {
                    char buffer[1024];
                    int len = recv(i, buffer, sizeof(buffer), 0);
                    if(len <= 0) {
                        // Client disconnected
                        cout << "[SERVER] Client disconnected: " << i << endl;
                        closesocket(i);
                        FD_CLR(i, &masterSet);
                        clients.erase(remove(clients.begin(), clients.end(), i), clients.end());
                    } else {
                        buffer[len] = '\0';
                        // Broadcast message
                        for(auto c : clients) {
                            if(c != i) send(c, buffer, len, 0);
                        }
                        cout << "[CLIENT " << i << "]: " << buffer << endl;
                    }
                }
            }
        }
    }

    closesocket(server);
    WSACleanup();
    return 0;
}

