#ifndef FNS_H
#define FNS_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <iostream>
#include <vector>

void user_input();
void start();
void process_char_input (int c, std::string &str, std::string &trail);
void move_cursor_back_a_line(std::string &str);
void erase_trail(std::string &trail);
std::string get_last_line(std::string str);

#endif
