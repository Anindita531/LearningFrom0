#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Generate a random number within range
int generateRandomNumber(int range) {
    return rand() % range + 1;
}

// Give user a hint based on their guess
void giveHint(int actual, int guess) {
    if (guess == actual) {
        cout << "\n?? Correct Guess! Congratulations!!\n";
        cout << "Your Guess: " << guess << "\n";
        cout << "Actual Number: " << actual << "\n";
    } else if (guess < actual) {
        cout << "?? Too Low! Try a higher number.\n";
    } else {
        cout << "?? Too High! Try a lower number.\n";
    }
}

// Display farewell message
string farewell() {
    return "\n?? Thanks for playing the Guess Game! ??\n";
}

// Generate number based on selected level
int generateLevel(int ch, int &maxLimit) {
    if (ch == 1) {
        maxLimit = 50;
        cout << "\n?? EASY MODE: Guess a number between 1 and 50.\n";
    } else if (ch == 2) {
        maxLimit = 100;
        cout << "\n?? MEDIUM MODE: Guess a number between 1 and 100.\n";
    } else if (ch == 3) {
        maxLimit = 500;
        cout << "\n?? HARD MODE: Guess a number between 1 and 500.\n";
    } else {
        maxLimit = 100; // Default fallback
        cout << "\n?? Invalid choice. Defaulting to MEDIUM mode (1–100).\n";
    }
    return generateRandomNumber(maxLimit);
}

int main() {
    srand(time(0)); // Seed for random numbers
    char playAgain;

    cout << "?? Welcome to the 'Guess the Number' Game! ??\n";

    do {
        int userGuess, attempts = 0, levelChoice, maxLimit;

        // Ask for level choice
        cout << "\nChoose Difficulty Level:\n";
        cout << "1. Easy (1–50)\n2. Medium (1–100)\n3. Hard (1–500)\n";
        cout << "Enter your choice: ";
        cin >> levelChoice;

        // Generate number based on level
        int actualNumber = generateLevel(levelChoice, maxLimit);

        // Start guessing loop
        while (true) {
            cout << "\nEnter your guess: ";
            cin >> userGuess;
            attempts++;

            if (userGuess < 1 || userGuess > maxLimit) {
                cout << "?? Invalid guess! Please enter a number between 1 and " << maxLimit << ".\n";
                continue;
            }

            giveHint(actualNumber, userGuess);

            if (userGuess == actualNumber) {
                cout << "? You guessed it in " << attempts << " attempt(s)!\n";
                break;
            }
        }

        // Ask to play again
        cout << "\n?? Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << farewell();
    return 0;
}

