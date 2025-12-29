#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int marks;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your marks (0 – 100): ";
    cin >> marks;

    cout << "\nHi " << name << "!\n";

    // Grading System
    if (marks >= 90 && marks <= 100) {
        cout << "?? Your Grade: A+\n";
        cout << "?? Message: You're a rockstar! Keep it up!\n";
    } else if (marks >= 80) {
        cout << "?? Your Grade: A\n";
        cout << "?? Message: Great job! Keep pushing toward excellence.\n";
    } else if (marks >= 70) {
        cout << "?? Your Grade: B\n";
        cout << "?? Message: You're doing well, aim even higher.\n";
    } else if (marks >= 60) {
        cout << "?? Your Grade: C\n";
        cout << "?? Message: You passed! Let’s improve more.\n";
    } else if (marks >= 50) {
        cout << "?? Your Grade: D\n";
        cout << "?? Message: Barely made it, don’t give up!\n";
    } else if (marks < 50 && marks >= 0) {
        cout << "?? Your Grade: F\n";
        cout << "?? Message: Failure is a step to success. Try again!\n";
    } else {
        cout << "? Invalid Marks Entered. Please enter 0–100.\n";
    }

    return 0;
}

