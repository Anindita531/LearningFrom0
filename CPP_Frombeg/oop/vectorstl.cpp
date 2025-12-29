#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr[] = {10, 20, 30};
    vector<int> v(arr, arr + 3); // initialize vector from array

    cout << "Vector elements: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    v.pop_back(); // remove last element

    cout << "\nAfter pop_back: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    return 0;
}

