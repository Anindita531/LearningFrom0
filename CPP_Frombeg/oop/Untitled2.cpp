#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

class ATM {
private:
    string name;
    float balance = 0;
    int accountNumber;

public:
    ATM() {
        int acnumber = rand() % 99999;
        accountNumber = acnumber;
    }

    void setName(string userName) {
        name = userName;
    }

    float deposit(float amount) {
        if (amount < 0) {
            cout << "Amount should be positive\n";
            return balance;
        }
        balance += amount;
        return balance;
    }

    float withdraw(float amount) {
        if (balance < amount) {
            cout << "You have not sufficient amount to withdraw\n";
            return balance;
        }
        balance -= amount;
        return balance;
    }

    float checkBalance() {
        return balance;
    }

    void display() {
        cout << "Account Details:\n";
        cout << "Name: " << name << "\n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Balance: " << balance << "\n";
    }
};

int main() {
    srand(time(0)); // ? Seed the random number generator

    ATM a1;
    string userName;
    float initialAmount;

    cout << "Enter Name: ";
    getline(cin, userName);
    a1.setName(userName);

    cout << "Enter Initial Amount: ";
    cin >> initialAmount;
    a1.deposit(initialAmount);

    a1.display();
    return 0;
}

