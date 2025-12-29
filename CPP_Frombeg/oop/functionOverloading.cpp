#include <iostream>
using namespace std;

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }
    double add(double a, double b) {
        return a + b;
    }
};

int main() {
    Calculator calc;
    cout << calc.add(5, 3) << endl;       // calls int version
    cout << calc.add(4.5, 3.2) << endl;   // calls double version
    return 0;
}

