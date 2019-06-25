#ifndef PLATFORM_H
#define PLATFORM_H

#include "class.h"
#include <iostream>
#include <vector>

extern std::vector<Command> history;
extern Command_Line_Status status;

void user_input();
void process_char_input(int c, Command &command, std::string &trail);
void erase_line(int size);
void save_command(Command &command);
void save_new_command(Command &command);

#endif
