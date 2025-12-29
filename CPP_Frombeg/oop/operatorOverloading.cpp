#include <iostream>
using namespace std;

class Number {
    int value;
public:
    Number(int v) { value = v; }

    // Overload + operator
    Number operator<<(Number n) {
        return Number(value + n.value);
    }

    void show() { cout << value << endl; }
};

int main() {
    Number n1(5), n2(10);
    Number n3 = n1 << n2; // calls overloaded +
    n3.show();
    return 0;
}

