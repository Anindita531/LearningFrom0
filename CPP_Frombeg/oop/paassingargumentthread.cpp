#include <iostream>
#include <thread>
using namespace std;

void printNum(int n) {
    cout << "Number: " << n << endl;
}

int main() {
    thread t1(printNum, 10);
    t1.join();
}

