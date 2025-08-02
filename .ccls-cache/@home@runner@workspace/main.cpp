#include <iostream>
#include <iomanip>
#include <limits>  

int main() {
    int startingPopulation;
    double dailyIncreasePercentage;
    int numberOfDays;
    double currentPopulation; 
    while (true) {
        std::cout << "Enter the starting number of organisms (2 or more): ";
        std::cin >> startingPopulation;
        if (std::cin.fail() || startingPopulation < 2) {
            std::cout << "Invalid input. Please enter a number 2 or greater.\n";
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        } else {
            break;
        }
    }

    while (true) {
        std::cout << "Enter their average daily population increase (as a percentage, e.g., 5 for 5%): ";
        std::cin >> dailyIncreasePercentage;
        if (std::cin.fail() || dailyIncreasePercentage < 0) { //
            std::cout << "Invalid input. Please enter a non-negative percentage.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    dailyIncreasePercentage = dailyIncreasePercentage / 100.0;

    while (true) {
        std::cout << "Enter the number of days they will multiply (1 or more): ";
        std::cin >> numberOfDays;
        if (std::cin.fail() || numberOfDays < 1) { 
            std::cout << "Invalid input. Please enter a number 1 or greater.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    currentPopulation = startingPopulation;
    std::cout << std::fixed << std::setprecision(0);

    std::cout << "\nPopulation Growth:\n";
    for (int day = 1; day <= numberOfDays; ++day) {
        std::cout << "Day " << day << ": Population = " << currentPopulation << std::endl;
        currentPopulation = currentPopulation + (currentPopulation * dailyIncreasePercentage);
    }

    return 0;
}