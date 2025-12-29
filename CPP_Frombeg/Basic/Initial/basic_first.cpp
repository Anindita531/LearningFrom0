#include <iostream>
#include <chrono>  // For timing
using namespace std;
using namespace std::chrono;

int main() {

    // -------- TASK 1 --------
    auto start1 = high_resolution_clock::now();

    int age = 20;
    float height = 5.6;
    char grade = 'A';
    bool isStudent = true;

    cout << "Age: " << age << "\n";
    cout << "Height: " << height << "\n";
    cout << "Grade: " << grade << "\n";
    cout << "Is Student? " << isStudent << "\n";

    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(end1 - start1);
    cout << "TASK 1 Execution time: " << duration1.count() << " ms\n\n";


    // -------- TASK 2 --------
    auto start2 = high_resolution_clock::now();

    int a,b;
    cout << "Enter First Number? ";
    cin >> a;
    cout << "Enter Second Number? ";
    cin >> b;

    cout << "a + b = " << a + b << "\n";
    cout << "a - b = " << a - b << "\n";
    cout << "a * b = " << a * b << "\n";
    cout << "a / b = " << a / b << "\n"; // integer division
    cout << "a % b = " << a % b << "\n"; // remainder
    cout << "a > b? " << (a > b) << "\n";

    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(end2 - start2);
    cout << "TASK 2 Execution time: " << duration2.count() << " ms\n\n";


    // -------- TASK 3 --------
    auto start3 = high_resolution_clock::now();

    cout << (a>5 && b<10) << endl;
    cout << (a>5 || b>10) << endl;
    cout << !(a>5) << endl;

    auto end3 = high_resolution_clock::now();
    auto duration3 = duration_cast<milliseconds>(end3 - start3);
    cout << "TASK 3 Execution time: " << duration3.count() << " ms\n\n";


    // -------- TASK 4 --------
    auto start4 = high_resolution_clock::now();

    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of float: " << sizeof(float) << endl;
    cout << "Size of double: " << sizeof(double) << endl;
    cout << "Size of char: " << sizeof(char) << endl;
    cout << "Size of bool: " << sizeof(bool) << endl;

    auto end4 = high_resolution_clock::now();
    auto duration4 = duration_cast<milliseconds>(end4 - start4);
    cout << "TASK 4 Execution time: " << duration4.count() << " ms\n\n";


    // -------- TASK 5 --------
    auto start5 = high_resolution_clock::now();

    int x = 121;
    int y = 233;
    cout << "x & y = " << (x & y) << "\n";  
    cout << "x || y = " << (x || y) << "\n";  
    cout << "a ^ b = " << (a ^ b) << "\n";  
    cout << "~a? " << ~a << "\n";

    auto end5 = high_resolution_clock::now();
    auto duration5 = duration_cast<milliseconds>(end5 - start5);
    cout << "TASK 5 Execution time: " << duration5.count() << " ms\n\n";


    return 0;
}

