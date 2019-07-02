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
void move_cursor_up(std::string &str);

#endif
