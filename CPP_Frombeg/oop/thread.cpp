#include <iostream>
#include <thread>
using namespace std;

void task() {
    cout << "Thread is running!" << endl;
}

int main() {
    thread t1(task);   // create thread
    t1.join();         // wait until t1 finishes
    cout << "Main thread finished!" << endl;
    return 0;
}

