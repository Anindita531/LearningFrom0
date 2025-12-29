#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cout << "Enter your name: ";
    getline(cin, name); // takes full line input
    cout << "Hello, " << name << "!Your  Name have total = " << name.length()<< " letters";
    return 0;
}

