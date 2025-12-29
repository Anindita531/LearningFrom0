#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;
    float marks;

public:
    // Setters
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setMarks(float m) { marks = m; }

    // Getters
    string getName() { return name; }
    int getAge() { return age; }
    float getMarks() { return marks; }

    void displayInfo() {
        cout << "Name: " << name << "\nAge: " << age << "\nMarks: " << marks << endl;
    }
};

int main() {
    Student s1;
    s1.setName("Anindita");
    s1.setAge(21);
    s1.setMarks(91.2);

    cout << "Student Info:\n";
    s1.displayInfo();

    cout << "\nAccessing via getters:\n";
    cout << "Name: " << s1.getName() << ", Age: " << s1.getAge() << ", Marks: " << s1.getMarks() << endl;

    return 0;
}

