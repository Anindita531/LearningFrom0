#include <iostream>
using namespace std;

class Engine {
    int rpm;
public:
    Engine(int r) : rpm(r) {}
    friend class Car;  // Car can access private data
};

class Car {
public:
    void showRPM(Engine e) {
        cout << "Engine RPM = " << e.rpm << endl;
    }
};

int main() {
    Engine e(4500);
    Car c;
    c.showRPM(e);
    return 0;
}

