#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() final {
        cout << "Base class function\n";
    }
};

class Derived : public Base {
    // ? Error: Cannot override a final function
    // void show() override {}
};

int main() {
    Base b;
    b.show();
    return 0;
}

