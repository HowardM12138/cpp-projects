#ifndef FNS_H
#define FNS_H

#include "class.h"
#include "platform.h"
#include <iostream>
#include <vector>

extern std::vector<std::string> errors;

void process_command(Command &command);
void end();
void reboot();
void print_command_history();
void gcc(std::vector<std::string> files);
void execute(std::vector<std::string> files);
void print_errors();
std::vector<std::string> get_file_names_from_str(std::string str);
bool is_valid_file_name(std::string str, std::string extension);

#endif
