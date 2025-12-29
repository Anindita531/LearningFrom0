#include <iostream>
using namespace std;

class Vehicle { // Base class
public:
    string brand;
    void honk() {
        cout << "Beep! Beep!" << endl;
    }
};

class Car : public Vehicle { // Derived class
public:
    string model;
    void showDetails() {
        cout << "Brand: " << brand << ", Model: " << model << endl;
    }
};

int main() {
    Car myCar;
    myCar.brand = "Honda"; // inherited attribute
    myCar.model = "City";
    myCar.honk();          // inherited method
    myCar.showDetails();   // derived method

    return 0;
}

