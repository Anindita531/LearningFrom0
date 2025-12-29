#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFile("example.txt");  // Open file for reading
    string line;

    if (!inFile) {
        cout << "Error opening file!";
        return 1;
    }

    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
    return 0;
}

