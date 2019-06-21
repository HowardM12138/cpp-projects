#include <iostream>
#include <vector>

int instruction_count = 0;

std::string find_the_third_tower_label(std::string first, std::string second) {

  std::vector<std::string> towers = {"A", "B", "C"};

  for (int i = 0; i < towers.size(); i++) {
    if (towers.at(i) == first || towers.at(i) == second) {

      towers.erase(towers.begin() + i);
      i--;

    }
  }
  return towers.at(0);
}

void towerOfHanoi(int disks, std::string start, std::string end) {
  if (disks == 1) {

    instruction_count++;
    std::cout << instruction_count << ". " << "Disk " << 1 << " from " << start << " to " << end << ".\n";

  } else {

    towerOfHanoi(disks - 1, start, find_the_third_tower_label(start, end));

    instruction_count++;
    std::cout << instruction_count << ". " << "Disk " << disks << " from " << start << " to " << end << ".\n";

    towerOfHanoi(disks - 1, find_the_third_tower_label(start, end), end);

  }
}
