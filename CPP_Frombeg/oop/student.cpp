#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;
    float marks;

    void displayInfo() {
        cout << "Name: " << name << "\nAge: " << age << "\nMarks: " << marks << endl;
    }

    void updateMarks(float newMarks) {
        marks = newMarks;
    }
};

int main() {
    Student s1, s2;

    s1.name = "Anindita";
    s1.age = 21;
    s1.marks = 88.5;

    s2.name = "Ravi";
    s2.age = 22;
    s2.marks = 76.0;

    s1.displayInfo();
    s2.displayInfo();

    cout << "\nUpdating Ravi's marks...\n";
    s2.updateMarks(82.3);
    s2.displayInfo();

    return 0;
}

