#include <iostream>
#include <memory>
using namespace std;

int main() {
    shared_ptr<int> ptr1 = make_shared<int>(500);
    cout << "ptr1 value: " << *ptr1 << endl;
    cout << "ptr1 use count: " << ptr1.use_count() << endl;

    shared_ptr<int> ptr2 = ptr1;  // Shared ownership
    cout << "ptr1 use count: " << ptr1.use_count() << endl;
    cout << "ptr2 use count: " << ptr2.use_count() << endl;

    return 0;
}

