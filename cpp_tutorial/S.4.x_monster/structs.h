#ifndef STRUCTS_H
#define STRICTS_H

#include <iostream>

enum Monster_Type {
    ORGE,
    DRAGON,
    ORC,
    GIANT_SPIDER,
    SLIME
};

struct Monster {
    Monster_Type type;
    int health;
    std::string name;
};

#endif
