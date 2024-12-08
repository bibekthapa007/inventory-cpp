#include <iostream>
#include <limits>

#include "input.h"

/**
 * @brief Safely reads a double value from standard input.
 *
 * This function repeatedly prompts the user for input until a valid int value is entered.
 * It handles invalid input by clearing the error flag and discarding the invalid input.
 *
 * @return The valid double value entered by the user.
 */
int getIntInput() {
    int value;
    while (true) {
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid input. Please enter an integer: ";
        } else {
            return value;
        }
    }
}


/**
 * @brief Safely reads a double value from standard input.
 *
 * This function repeatedly prompts the user for input until a valid double value is entered.
 * It handles invalid input by clearing the error flag and discarding the invalid input.
 *
 * @return The valid double value entered by the user.
 */
double getDoubleInput() {
    double value;
    while (true) {
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid input. Please enter a number: ";
        } else {
            return value;
        }
    }
}