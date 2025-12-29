#include <iostream>
using namespace std;

class Vehicle {      // Base class
public:
    void start() {
        cout << "Vehicle started" << endl;
    }
};

class Car : public Vehicle { // Derived class
public:
    void drive() {
        cout << "Car is driving" << endl;
    }
};

int main() {
    Car myCar;
    myCar.start();  // inherited
    myCar.drive();  // own method
    return 0;
}

