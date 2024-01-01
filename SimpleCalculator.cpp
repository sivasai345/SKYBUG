#include <iostream>

int main() {
    double num1, num2;
    char operation;

    // Get user input
    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    std::cout << "Choose operation (+, -, *, /): ";
    std::cin >> operation;

    // Perform calculation based on the chosen operation
    switch (operation) {
        case '+':
            std::cout << num1 << " + " << num2 << " = " << num1 + num2 << "\n";
            break;
        case '-':
            std::cout << num1 << " - " << num2 << " = " << num1 - num2 << "\n";
            break;
        case '*':
            std::cout << num1 << " * " << num2 << " = " << num1 * num2 << "\n";
            break;
        case '/':
            if (num2 != 0) {
                std::cout << num1 << " / " << num2 << " = " << num1 / num2 << "\n";
            } else {
                std::cout << "Error: Division by zero is not allowed.\n";
            }
            break;
        default:
            std::cout << "Invalid operation. Please choose +, -, *, or /.\n";
    }

    return 0;
}
