#include "structs.h"
#include <iostream>

Monster construct_monster(Monster_Type type, int health, std::string name) {
    Monster monster = {type, health, name};
    return monster;
}

std::string get_monster_type(Monster_Type type) {
    if (type == ORGE) return "Orge";
    if (type == ORC) return "Orc";
    if (type == DRAGON) return "Dragon";
    if (type == GIANT_SPIDER) return "Giant Spider";
    if (type == SLIME) return "Slime";

    return "Unknown";
}

void print_monster(Monster monster) {
    std::cout << "This " << get_monster_type(monster.type) << " is named " <<
        monster.name << " and has health: " << monster.health << "\n";
}

int main() {
    Monster monster1 = construct_monster(ORGE, 100, "Torg");
    print_monster(monster1);

    Monster monster2 = construct_monster(SLIME, 23, "Blurp");
    print_monster(monster2);

    return 0;
}
