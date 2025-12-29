#include <iostream>
using namespace std;

int main() {
    int *p = new int; // single int
    *p = 10;
    cout << *p << endl;
    delete p; // free single int

    int *arr = new int[5]; // array of 5 ints
    for(int i=0;i<5;i++) arr[i]=i+1;
    for(int i=0;i<5;i++) cout << arr[i] << " ";
    cout << endl;
    delete[] arr; // free array
    return 0;
}

