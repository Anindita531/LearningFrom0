#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    int a, b;

    // -------- INPUT --------
    cout << "Enter First Number? ";
    cin >> a;
    cout << "Enter Second Number? ";
    cin >> b;

    // -------- TIMER START (ONLY CALCULATIONS) --------
    auto startCalc = high_resolution_clock::now();

    // Calculations
    int sum = a + b;
    int diff = a - b;
    int prod = a * b;
    int div = a / b;
    int mod = a % b;
    bool comp = a > b;

    // Output
    cout << "a + b = " << sum << "\n";
    cout << "a - b = " << diff << "\n";
    cout << "a * b = " << prod << "\n";
    cout << "a / b = " << div << "\n";
    cout << "a % b = " << mod << "\n";
    cout << "a > b? " << comp << "\n";

    // -------- TIMER END --------
    auto endCalc = high_resolution_clock::now();
    auto durationCalc = duration_cast<microseconds>(endCalc - startCalc);
    cout << "TASK 2 (Calculations only) Execution time: " << durationCalc.count() << " µs \n";

    return 0;
}

