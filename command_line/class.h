#ifndef CLASS_H
#define CLASS_H

#include <string>

enum Command_Line_Status {
    ON,
    OFF,
    FAIL
};

struct Command {
    std::string command;
    std::string str;
    int index;
};

#endif
