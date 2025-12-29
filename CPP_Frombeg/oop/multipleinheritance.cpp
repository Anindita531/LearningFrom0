#include <iostream>
using namespace std;

class Engine {
public:
    void startEngine() { cout << "Engine started" << endl; }
};

class GPS {
public:
    void showGPS() { cout << "GPS active" << endl; }
};

class Car : public Engine, public GPS {  // inherits from both
};

int main() {
    Car c;
    c.startEngine();
    c.showGPS();
    return 0;
}

