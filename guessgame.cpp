#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    
    std::srand(std::time(0));
    int secretNumber = std::rand() % 100 + 1;

    int userGuess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have chosen a number between 1 and 100. Can you guess it?" << std::endl;

    do {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        attempts++;

        if (userGuess == secretNumber) {
            std::cout << "Congratulations! You guessed the correct number in " << attempts << " attempts!" << std::endl;
            break;
        } else if (userGuess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else {
            std::cout << "Too high! Try again." << std::endl;
        }

    } while (true);

    return 0;
}
