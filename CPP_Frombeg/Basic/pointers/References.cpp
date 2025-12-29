#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int &ref = a; // ref refers to a
    ref = 20;     // changes a
    cout << "a = " << a << endl;
    return 0;
}

