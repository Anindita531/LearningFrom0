#include <iostream>
using namespace std;

class Car {
public: // Access modifier
    string brand;
    int year;

    void display() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

int main() {
    Car c1; // Object creation
    c1.brand = "Toyota";
    c1.year = 2020;
    c1.display();

    Car c2; // Another object
    c2.brand = "Tesla";
    c2.year = 2023;
    c2.display();

    return 0;
}

