#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int roll;

    Student(string n, int r) {
        name = n;
        roll = r;
        cout << "Constructor called for " << name << endl;
    }

    ~Student() { // Destructor
        cout << "Destructor called for " << name << endl;
    }
};

int main() {
    Student s1("Anindita", 20);
    Student s2("Bonghee", 202);
}

