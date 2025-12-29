#include <iostream>
using namespace std;

class Person {
public:
    string name;
};

class Employee : public Person {
public:
    int empID;
};

class Manager : public Employee {
public:
    int teamSize;
};

int main() {
    Manager m;
    m.name = "Alice";
    m.empID = 101;
    m.teamSize = 5;

    cout << m.name << ", ID: " << m.empID << ", Team: " << m.teamSize << endl;
    return 0;
}

