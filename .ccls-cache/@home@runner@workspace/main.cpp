#include <iostream>
#include <string>
#include <vector>
#include <fstream> 
#include <iomanip> 
#include <limits> 

int main() {

    const int STARTING_YEAR = 1900;
    const int YEAR_INTERVAL = 20;
    const int ASTERISK_UNIT = 1000;

    std::string townName;
    std::string fileName;
    std::vector<int> populationData;
    std::cout << "Enter the name of the data file (e.g., People.txt): "; 
    std::getline(std::cin, fileName);

    std::ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        int population;
        while (inputFile >> population) {
            populationData.push_back(population);
        }
        inputFile.close();
    } else {
        std::cerr << "Error: Could not open file '" << fileName << "'.\n";
        std::cerr << "Proceeding with hardcoded data for demonstration purposes.\n";
    
        populationData = {2000, 4000, 5000, 9000, 14000, 18000};
    }

   
    std::cout << "Enter the name of the town: ";
    if (std::cin.peek() == '\n') {
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::getline(std::cin, townName);

    std::cout << "\n" << townName << " Population Growth\n";
    std::cout << "(each * represents 1,000 people)\n";

    int currentYear = STARTING_YEAR;
    for (int population : populationData) {
        int numAsterisks = static_cast<int>((population + (ASTERISK_UNIT / 2.0)) / ASTERISK_UNIT);

        std::cout << std::setw(4) << currentYear << " ";
        for (int i = 0; i < numAsterisks; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
        currentYear += YEAR_INTERVAL;
    }

    return 0;
}