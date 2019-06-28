#ifndef PLATFORM_H
#define PLATFORM_H

#include "class.h"
#include "fns.h"

#include <iostream>
#include <vector>
#include <unistd.h>
#include <dirent.h>

extern std::string COMMAND_HEADER;
extern std::vector<Command> history;
extern Command_Line_Status status;
extern DIR *directory;
extern char str_directory[4096];

void start();
void user_input();
void process_char_input(int c, Command &command, std::string &trail);
void erase_line(int size);
void save_command(Command &command);
void save_new_command(Command &command);

#endif
