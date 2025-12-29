#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
using namespace std;

int main() {
    string sentences[] = {
        "The sky is blue.",
        "C++ is fun!",
        "Always write clean code.",
        "Practice makes perfect.",
        "Stay curious and keep learning."
    };

    int size = sizeof(sentences) / sizeof(sentences[0]);

    srand(time(0)); // Seed the random number generator
    int randomIndex = rand() % size;

    cout << "Random sentence: " << sentences[randomIndex] << endl;

    return 0;
}

