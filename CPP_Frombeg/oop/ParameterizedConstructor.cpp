#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int roll;
    float marks;

    // Parameterized Constructor
    Student(string n, int r, float m) {
        name = n;
        roll = r;
        marks = m;
    }

    void display() {
        cout << "Name: " << name << ", Roll: " << roll << ", Marks: " << marks << endl;
    }
};

int main() {
    Student s1("Anindita", 20, 95.5); // Values at creation
    s1.display();
}

