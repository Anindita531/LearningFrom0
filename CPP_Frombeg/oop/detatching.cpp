#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void backgroundTask() {
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Background task done!" << endl;
}

int main() {
    thread t1(backgroundTask);
    t1.detach();  // runs in background
    cout << "Main thread exiting!" << endl;
    this_thread::sleep_for(chrono::seconds(3));
}

