#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator with the current time
    std::srand(std::time(0));

    // Generate a random number between 1 and 100
    int secretNumber = std::rand() % 100 + 1;

    int guess;
    int attempts = 0;

    std::cout << "Welcome to the Guess the Number Game!\n";
    std::cout << "Try to guess the number between 1 and 100.\n";

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        attempts++;

        if (guess < secretNumber) {
            std::cout << "Too low! Try again.\n\n";
        } else if (guess > secretNumber) {
            std::cout << "Too high! Try again.\n\n";
        } else {
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";
        }

    } while (guess != secretNumber);

    return 0;
}
