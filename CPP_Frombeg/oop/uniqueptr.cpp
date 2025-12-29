#include <iostream>
#include <memory>
using namespace std;

int main() {
    // Create a unique pointer
    unique_ptr<int> ptr1 = make_unique<int>(100);
    cout << "Value: " << *ptr1 << endl;

    // Transfer ownership to another unique_ptr
    unique_ptr<int> ptr2 = move(ptr1);

    if (!ptr1) 
        cout << "ptr1 is empty now." << endl;

    cout << "ptr2 value: " << *ptr2 << endl;

    return 0;
}

