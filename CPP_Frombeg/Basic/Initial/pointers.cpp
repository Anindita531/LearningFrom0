#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int *p = &a; // pointer stores address of a

    cout << "Address of a: " << p << endl;
    cout << "Value at pointer: " << *p << endl;
    *p=77;
	a = *p; // change value through pointer
    cout << "Value of a: " << a << endl;

    *p = 20; // change value through pointer
    cout << "New value of a: " << a << endl;
	int  marks[] = {90, 85, 78, 92, 88};
	int *ptr=marks;

    for(int i = 0; i < 5; i++) {
    cout << "Student " << i+1 << ": " << *(ptr + i) << endl; // ? pointer arithmetic
}

   
    return 0;
}

