#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int roll;
    float marks;

    // Default Constructor
    Student() {
        cout << "Default Constructor called\n";
        name = "Unknown";
        roll = 0;
        marks = 0.0;
    }

    void display() {
        cout << "Name: " << name << ", Roll: " << roll << ", Marks: " << marks << endl;
    }
};

int main() {
    Student s1; // Constructor automatically runs
    s1.display();
}

