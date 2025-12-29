#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("example.txt", ios::app);  // Append mode

    outFile << "This is appended text." << endl;
    outFile.close();

    cout << "Data appended successfully!" << endl;
    return 0;
}

