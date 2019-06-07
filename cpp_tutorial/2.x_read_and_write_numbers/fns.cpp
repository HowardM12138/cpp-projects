#include "fns.h"
#include <iostream>

int readNumber() {
    int x;
    std::cout << "Enter a number: \n";
    std::cin >> x;
    return x;
}

void writeNumber(int num) {
    std::cout << num << "\n";
}
