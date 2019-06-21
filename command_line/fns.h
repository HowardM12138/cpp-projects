#ifndef FNS_H
#define FNS_H

#include <iostream>
#include "command_line.h"

void start();
void reboot();
void end();

void user_input();

void process_command(Command &command);
void process_char_input(int c, Command &command, std::string &trail);
void save_command(Command &command);
void save_new_command(Command &command);
void erase_line(int size);

std::string error_message (Command &command);
void print_command_history();

#endif
