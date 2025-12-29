#include <iostream>
using namespace std;

class Test {
    const int val;
public:
    Test(int v) : val(v) {}
    int getVal() const {  // const method
        return val;
    }
};

int main() {
    const int x = 10;
    cout << "Const variable: " << x << endl;

    Test t(50);
    cout << "Const member: " << t.getVal() << endl;
    return 0;
}

