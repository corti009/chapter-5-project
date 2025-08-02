#include <iostream>

int main() {
    std::cout << "Pattern A:\n";
    for (int row = 1; row <= 10; ++row) {
        for (int col = 0; col < row; ++col) {
            std::cout << "+";
        }
        std::cout << std::endl; 
    }

    std::cout << "\nPattern B:\n";
    for (int row = 10; row >= 1; --row) {
        for (int col = 0; col < row; ++col) {
            std::cout << "+";
        }
        std::cout << std::endl; 
    }

    return 0;
}