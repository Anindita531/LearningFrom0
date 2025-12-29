#include <iostream>
using namespace std;

// ========== CASE 1: C++ WITHOUT VIRTUAL ==========
class Base1 {
public:
    void show() {
        cout << "[C++] Base1::show() called (NO virtual)" << endl;
    }
};

class Derived1 : public Base1 {
public:
    void show() {
        cout << "[C++] Derived1::show() called" << endl;
    }
};

// ========== CASE 2: C++ WITH VIRTUAL ==========
class Base2 {
public:
    virtual void show() {
        cout << "[C++] Base2::show() called (VIRTUAL)" << endl;
    }
};

class Derived2 : public Base2 {
public:
    void show() override {
        cout << "[C++] Derived2::show() called" << endl;
    }
};

int main() {
    cout << "===== CASE 1: C++ Without Virtual =====\n";
    Base1 *ptr1 = new Derived1();
    ptr1->show();   // Calls Base1::show()
    delete ptr1;

    cout << "\n===== CASE 2: C++ With Virtual =====\n";
    Base2 *ptr2 = new Derived2();
    ptr2->show();   // Calls Derived2::show()
    delete ptr2;

    return 0;
}

