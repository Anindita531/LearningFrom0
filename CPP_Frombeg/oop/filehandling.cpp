#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("example.csv");  // Create & open file

    if (!outFile) {
        cout << "Error opening file!";
        return 1;
    }

    outFile << "Hello, C++ File Handling!" << endl;
    outFile << "This is line 2." << endl;

    outFile.close();  // Always close the file
    cout << "Data written successfully!" << endl;

    return 0;
}

