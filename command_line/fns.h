#ifndef FNS_H
#define FNS_H

#include <iostream>
#include "command_line.h"

void rebuild();
void user_input();
void end();

void process_command(Command &command);
void process_char_input(int c, Command &command, std::string &trail);
void print_command_history();



#endif
