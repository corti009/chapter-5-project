#include <iostream>
#include <random>
#include <limits>
#include <ios>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);

    int secretNumber = dist(gen);
    int userGuess = 0;
    int guessCount = 0;

    std::cout << "Welcome to the Random Number Guessing Game!\n";
    std::cout << "I have a secret number between 1 and 100. Can you guess it?\n";
    do {
        guessCount++; 
        std::cout << "Guess #" << guessCount << ": Enter your guess: ";
        std::cin >> userGuess;
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            guessCount--; 
            continue;
        }

        if (userGuess < 1 || userGuess > 100) {
            std::cout << "Please guess a number between 1 and 100.\n";
            guessCount--; 
            continue; 
        }

        if (userGuess > secretNumber) {
            std::cout << "Too high, try again.\n";
        } else if (userGuess < secretNumber) {
            std::cout << "Too low, try again.\n";
        }
       
    } while (userGuess != secretNumber);
    std::cout << "\nCongratulations! You guessed the number " << secretNumber
              << " in " << guessCount << " tries!\n";

    return 0;
}