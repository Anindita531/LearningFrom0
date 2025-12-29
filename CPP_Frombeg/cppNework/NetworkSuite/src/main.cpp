#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int choice;

    while (true) {
        system("cls"); // Optional: clears screen
        cout << "\n==== NetworkSuite Menu ====\n";
        cout << "1. Ping\n";
        cout << "2. UDP Chat (Server)\n";
        cout << "3. UDP Chat (Client)\n";
        cout << "4. TCP Chat (Server)\n";
        cout << "5. TCP Chat (Client)\n";
        cout << "6. DNS Lookup\n";
        cout << "7. Traceroute\n";
        cout << "8. Packet Sniffer\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Launching Ping Tool...\n";
                system("build/ping.exe");
                break;
            case 2:
                cout << "Starting UDP Server...\n";
                system("build/udp_server.exe");
                break;
            case 3:
                cout << "Starting UDP Client...\n";
                system("build/udp_client.exe");
                break;
            case 4:
                cout << "Starting TCP Server...\n";
                system("build/tcp_server.exe");
                break;
            case 5:
                cout << "Starting TCP Client...\n";
                system("build/tcp_client.exe");
                break;
            case 6:
                cout << "Running DNS Lookup...\n";
                system("build/dns_lookup.exe");
                break;
            case 7:
                cout << "Running Traceroute...\n";
                system("build/traceroute.exe");
                break;
            case 8:
                cout << "Starting Packet Sniffer...\n";
                system("build/sniffer.exe");
                break;
            case 0:
                cout << "Exiting NetworkSuite.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}

