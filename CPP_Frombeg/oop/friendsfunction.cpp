#include <iostream>
using namespace std;

class Box {
private:
    int length;

public:
    Box(int l) : length(l) {}

    // Friend function declaration
    friend void showLength(Box b);
};

// Friend function definition (outside class)
void showLength(Box b) {
    cout << "Length = " << b.length << endl; // Directly accessing private data
}

int main() {
    Box b(10);
    showLength(b);  // Call like a normal function
    return 0;
}

