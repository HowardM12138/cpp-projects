#ifndef FNS_H
#define FNS_H

#include <stdlib.h>
#include <iostream>
#include <vector>

struct Line {
    std::string str;
    int index;
};

void user_input();
void start();
void process_char_input (int c, Line &line, std::string trail);

#endif
