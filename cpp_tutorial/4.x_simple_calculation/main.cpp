#include <iostream>

int main() {

    double num1;
    double num2;
    char operation;
    double result;

    std::cout << "Enter your first number: ";
    std::cin >> num1;
    std::cout << "Enter your second number: ";
    std::cin >> num2;
    std::cout << "Enter one of the following: +, -, *, /: ";
    std::cin >> operation;

    switch(static_cast<int>(operation)) {
        case 43:
            result = num1 + num2;
            break;
        case 45:
            result = num1 - num2;
            break;
        case 42:
            result = num1 * num2;
            break;
        case 47:
            result = num1 / num2;
            break;
        default:
            std::cout << "Invalid operator.\n";
            return 0;
    }

    std::cout << num1 << " " << operation << " " << num2 << " = " << result << "\n";
    return 0;
}
