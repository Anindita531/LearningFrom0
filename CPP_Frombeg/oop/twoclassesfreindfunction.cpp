#include <iostream>
using namespace std;
class B; // Forward declaration
class A {
    int x;
public:
    A(int val) : x(val) {}
    friend void sum(A, B); // Forward declaration of friend
};

class B {
    int y;
public:
    B(int val) : y(val) {}
    friend void sum(A, B);
};

// Friend function accessing both classes
void sum(A objA, B objB) {
    cout << "Sum = " << objA.x + objB.y << endl;
}

int main() {
    A a(5);
    B b(7);
    sum(a, b);
    return 0;
}

