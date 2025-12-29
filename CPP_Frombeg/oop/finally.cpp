#include <iostream>
using namespace std;

class Resource {
public:
    ~Resource() {
        cout << "Resource cleaned up automatically!\n";
    }
};

int main() {
    try {
        Resource r;  // destructor will be called automatically
        throw runtime_error("Some error!");
    }
    catch (...) {
        cout << "Exception caught\n";
    }
    return 0;
}

