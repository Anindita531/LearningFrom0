#include <iostream>
#include <ctime>
using namespace std;

int main() {
    clock_t start = clock();

    // Your code
  	//TASK 1
    int age = 20;
    float height = 5.6;
    char grade = 'A';
    bool isStudent = true;

    cout << "Age: " << age << "\n";
    cout << "Height: " << height << "\n";
    cout << "Grade: " << grade << "\n";
    cout << "Is Student? " << isStudent << "\n";
    
    //TASK 2
    int a,b;
    cout<<"Enter First Number? ";
    cin>>a;
    cout<<"Enter Second  Number? ";
    cin>>b;
    cout << "a + b = " << a + b << "\n";
    cout << "a - b = " << a - b << "\n";
    cout << "a * b = " << a * b << "\n";
    cout << "a / b = " << a / b << "\n"; // integer division
    cout << "a % b = " << a % b << "\n"; // remainder
    cout << "a > b? " << (a > b) << "\n";
    //Task 3
    cout << (a>5 && b<10) << endl; // 1
    cout << (a>5 || b>10) << endl; // 1
    cout << !(a>5) << endl;    
    //Task 4
	cout << "Size of int: " << sizeof(int) << endl;
	cout << "Size of float: " << sizeof(float) << endl;
	cout << "Size of double: " << sizeof(double) << endl;
	cout << "Size of char: " << sizeof(char) << endl;
	cout << "Size of bool: " << sizeof(bool) << endl;
	//TASK 5
	int  x=121;
	int y=233;
	cout << "x & y = " << (x & y) << "\n"; //  
	cout << "x || y = " << (x || y )<< "\n"; //  
	cout << "a ^ b = " << (a ^ b )<< "\n"; //  
    cout << "~a? " << ~a << "\n";

    clock_t end = clock();

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Execution time: " << time_taken << " seconds\n";

    return 0;
}

