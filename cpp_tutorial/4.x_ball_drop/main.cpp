#include "my_constants.h"
#include <iostream>
#include <cmath>

int main() {

    double height;
    int time = 0;

    std::cout << "Enter the height of the building: ";
    std::cin >> height;

    std::cout << "At " << time << " seconds, the ball is at height: " << height - 0.5 * my_constants::gravity * pow(time, 2) << " meters.\n";
    time++;
    std::cout << "At " << time << " seconds, the ball is at height: " << height - 0.5 * my_constants::gravity * pow(time, 2) << " meters.\n";
    time++;
    std::cout << "At " << time << " seconds, the ball is at height: " << height - 0.5 * my_constants::gravity * pow(time, 2) << " meters.\n";
    time++;
    std::cout << "At " << time << " seconds, the ball is at height: " << height - 0.5 * my_constants::gravity * pow(time, 2) << " meters.\n";
    time++;
    std::cout << "At " << time << " seconds, the ball is at height: " << height - 0.5 * my_constants::gravity * pow(time, 2) << " meters.\n";

    return 0;
}
