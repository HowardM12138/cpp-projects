#ifndef PLATFORM_H
#define PLATFORM_H

#include "class.h"
#include <iostream>
#include <vector>

std::vector<Command> history;
const std::string COMMAND_HEADER = "C:\\WINDOWS\\system32>~$ ";
Command_Line_Status status = OFF;

void user_input();
void process_char_input(int c, Command &command, std::string &trail);
void erase_line(int size);
void save_command(Command &command);
void save_new_command(Command &command);

#endif
