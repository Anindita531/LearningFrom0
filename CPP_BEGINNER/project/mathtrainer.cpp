#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

// ---------------- Function Declarations ----------------
void welcome();
int selectLevel();
char randomOperator();
int generateQuestion(int maxRange, int &correctAns);
void showScore(int correct, int total);
bool playAgain();

// ---------------- Main Function ----------------
int main() {
    srand(time(0));  // Seed random generator
    
    welcome();

    do {
        // Select difficulty level
        int maxRange = selectLevel();
        int totalQuestions = 0, correctAnswers = 0;

        cout << "\nLet's start the quiz! ??\n";
        cout << "Type 0 anytime to quit.\n\n";

        while (true) {
            int correctAns;
            int userAns = generateQuestion(maxRange, correctAns);

            // If user wants to exit
            if (userAns == 0) {
                cout << "\nExiting quiz...\n";
                break;
            }

            totalQuestions++;

            // Check correctness
            if (userAns == correctAns) {
                cout << "? Correct! Well done.\n\n";
                correctAnswers++;
            } else {
                cout << "? Oops! Correct answer was: " << correctAns << "\n\n";
            }
        }

        // Show final score
        showScore(correctAnswers, totalQuestions);

    } while (playAgain());

    cout << "\n***** Thanks for using Math Trainer! See you again. *****\n";
    return 0;
}

// ---------------- Function Definitions ----------------

// Welcome Screen
void welcome() {
    cout << "=====================================\n";
    cout << "       ?? WELCOME TO MATH TRAINER ??\n";
    cout << "=====================================\n";
    cout << "Rules:\n";
    cout << "1. Solve random math problems.\n";
    cout << "2. Enter 0 anytime to quit.\n";
    cout << "3. Final score will be shown at the end.\n";
    cout << "-------------------------------------\n";
}

// Difficulty Selection
int selectLevel() {
    int choice;
    cout << "\nChoose Difficulty Level:\n";
    cout << "1. Easy   (Numbers 1 to 10)\n";
    cout << "2. Medium (Numbers 1 to 50)\n";
    cout << "3. Hard   (Numbers 1 to 100)\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: return 10;
        case 2: return 50;
        case 3: return 100;
        default:
            cout << "Invalid choice! Defaulting to Easy.\n";
            return 10;
    }
}

// Generate Random Operator (+, -, *, /)
char randomOperator() {
    char operators[] = {'+', '-', '*', '/'};
    return operators[rand() % 4];
}

// Generate a Random Math Question
int generateQuestion(int maxRange, int &correctAns) {
    int num1 = rand() % maxRange + 1;
    int num2 = rand() % maxRange + 1;
    char op = randomOperator();

    // Avoid division by zero
    if (op == '/' && num2 == 0) num2 = 1;

    cout << "Solve: " << num1 << " " << op << " " << num2 << " = ";
    int userAns;
    cin >> userAns;

    // Calculate correct answer
    switch (op) {
        case '+': correctAns = num1 + num2; break;
        case '-': correctAns = num1 - num2; break;
        case '*': correctAns = num1 * num2; break;
        case '/': correctAns = num1 / num2; break;
    }

    return userAns;
}

// Show Final Score & Accuracy
void showScore(int correct, int total) {
    cout << "\n========= QUIZ RESULT =========\n";
    cout << "Total Questions Attempted: " << total << "\n";
    cout << "Correct Answers         : " << correct << "\n";
    cout << "Wrong Answers           : " << total - correct << "\n";

    if (total > 0) {
        double accuracy = ((double)correct / total) * 100;
        cout << fixed << setprecision(2);
        cout << "Accuracy               : " << accuracy << "%\n";
    } else {
        cout << "Accuracy               : 0%\n";
    }
    cout << "===============================\n";
}

// Replay Option
bool playAgain() {
    char choice;
    cout << "\nDo you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

