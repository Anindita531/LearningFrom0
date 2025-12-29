#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() { // virtual for runtime polymorphism
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override { // overrides base function
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    a1->sound(); // Dog barks
    a2->sound(); // Cat meows

    delete a1;
    delete a2;
    return 0;
}

