#include "fns.h"
#include <iostream>

int main() {

    int num1;
    std::cout << "Please enter a number: ";
    std::cin >> num1;
    std::cout << "The number is even: " << isEven(num1) << "\n";

    return 0;
}
