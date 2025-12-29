#include <iostream>
using namespace std;

int main() {
    int x = 462;
    int* ptr = &x; // pointer to x
    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Pointer storing: " << ptr << endl;
    cout << "Value via pointer: " << *ptr << endl; // dereferencing
    return 0;
}

