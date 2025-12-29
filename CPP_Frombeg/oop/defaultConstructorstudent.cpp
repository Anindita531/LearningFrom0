#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    // Default constructor
    Student() {
        name = "Unknown";
        age = 0;
        cout << "Default constructor called\n";
    }

    // Parameterized constructor
    Student(string n, int a) {
        name = n;
        age = a;
        cout << "Parameterized constructor called\n";
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Student s1; // Default constructor
    s1.display();

    Student s2("Alice", 20); // Parameterized constructor
    s2.display();

    return 0;
}

