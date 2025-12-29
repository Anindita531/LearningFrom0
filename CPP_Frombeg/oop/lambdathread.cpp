#include <iostream>
#include <thread>
using namespace std;

int main() {
    thread t1([]() {
        cout << "Lambda thread running!" << endl;
    });

    t1.join();
    return 0;
}

