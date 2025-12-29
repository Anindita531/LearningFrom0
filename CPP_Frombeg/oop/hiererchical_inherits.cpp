#include <iostream>
using namespace std;

class Vehicle {
public:
    void start() { cout << "Vehicle started" << endl; }
};

class Car : public Vehicle {
public:
    void drive() { cout << "Car driving" << endl; }
};

class Bike : public Vehicle {
public:
    void ride() { cout << "Bike riding" << endl; }
};

int main() {
    Car c;
    Bike b;
    c.start();  // inherited
    c.drive();
    b.start();  // inherited
    b.ride();
    return 0;
}

