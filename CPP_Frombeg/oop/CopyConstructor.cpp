#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int roll;
    float marks;

    Student(string n, int r, float m) {
        name = n;
        roll = r;
        marks = m;
    }

    // Copy Constructor
    Student(const Student &s) {
        name = s.name;
        roll = s.roll;
        marks = s.marks;
    }

    void display() {
        cout << "Name: " << name << ", Roll: " << roll << ", Marks: " << marks << endl;
    }
};

int main() {
    Student s1("Anindita", 20, 95.5);
    Student s2 = s1; // Calls copy constructor
    s2.display();
}

