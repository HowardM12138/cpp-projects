#ifndef FNS_H
#define FNS_H

#include "class.h"
#include "platform.h"
#include "ls.h"
#include <iostream>
#include <bits/stdc++.h> 
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>

extern std::vector<std::string> errors;

void process_command(Command &command);
void end();
void reboot();
void print_command_history();
void cd(std::string path);
void touch(std::string file_name);
void gcc(std::string str);
void execute(std::string str);
void print_errors();
std::vector<std::string> get_file_names_from_str(std::string str);
bool is_valid_file_name(std::string str, std::string extension);

#endif
