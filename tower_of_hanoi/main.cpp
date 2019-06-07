#include <iostream>
#include "fns.hpp"
int main() {
  int num_of_disks;
  std::cout << "Enter the number of disks for the game: ";
  std::cin >> num_of_disks;
  towerOfHanoi(num_of_disks, "A", "C");
}
