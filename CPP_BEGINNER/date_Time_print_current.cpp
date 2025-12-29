#include <iostream>
#include <ctime>
using namespace std;

int main() {
    time_t now = time(0); // Get current time
    tm *ltm = localtime(&now); // Convert to local time

    cout << "Today's date and time: ";
    cout << 1900 + ltm->tm_year << "-"
         << 1 + ltm->tm_mon << "-"
         << ltm->tm_mday << " "
         << ltm->tm_hour << ":"
         << ltm->tm_min << ":"
         << ltm->tm_sec << endl;

    return 0;
}

