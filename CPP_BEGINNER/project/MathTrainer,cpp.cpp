#include <iostream>
#include <cmath>
using namespace std;

// Factorial using recursion
int factorial(int n) {
    if (n == 0 || n == 1)   // Base Case
        return 1;
    return n * factorial(n - 1);  // Recursive Call
}

// Fibonacci using recursion
int fibonacci(int n) {
    if (n == 0) return 0;   // Base Case
    if (n == 1) return 1;   // Base Case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Sum of first N natural numbers using recursion
int sumNatural(int n) {
    if (n == 0)  // Base Case
        return 0;
    return n + sumNatural(n - 1);
}

// Power of a number (base^exp)
int power(int base, int exp) {
    if (exp == 0)   // Base Case
        return 1;
    return base * power(base, exp - 1);
}

// Display menu
void showMenu() {
    cout << "\n========== Recursion Math Trainer ==========\n";
    cout << "1. Factorial Calculator\n";
    cout << "2. Fibonacci Series\n";
    cout << "3. Sum of First N Natural Numbers\n";
    cout << "4. Power of a Number\n";
    cout << "5. Exit\n";
    cout << "===========================================\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    char cont;

    do {
        showMenu();
        cin >> choice;

        switch(choice) {
            case 1: {
                int n;
                cout << "Enter a number: ";
                cin >> n;
                cout << "Factorial of " << n << " = " << factorial(n) << endl;
                break;
            }

            case 2: {
                int n;
                cout << "Enter number of terms: ";
                cin >> n;
                cout << "Fibonacci Series: ";
                for (int i = 0; i < n; i++) {
                    cout << fibonacci(i) << " ";
                }
                cout << endl;
                break;
            }

            case 3: {
                int n;
                cout << "Enter a number: ";
                cin >> n;
                cout << "Sum of first " << n << " numbers = " << sumNatural(n) << endl;
                break;
            }

            case 4: {
                int base, exp;
                cout << "Enter base: ";
                cin >> base;
                cout << "Enter exponent: ";
                cin >> exp;
                cout << base << "^" << exp << " = " << power(base, exp) << endl;
                break;
            }

            case 5:
                cout << "Thank you for using Recursion Math Trainer! ??" << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

        cout << "\nDo you want to try another option? (y/n): ";
        cin >> cont;

    } while (cont == 'y' || cont == 'Y');

    cout << "\nGoodbye! ??\n";
    return 0;
}

