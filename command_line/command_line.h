#ifndef COMMAND_LINE_H
#define COMMAND_LINE_H

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
    bool is_valid;
};

#endif
