#include <iostream>
using namespace std;

class Student {
    string name;
public:
    void setName(string name) {
        this->name = name; // distinguishes attribute from parameter
    }
    void display() {
        cout << "Name: " << name << endl;
    }
};

int main() {
    Student s;
    s.setName("Bob");
    s.display();

    return 0;
}

