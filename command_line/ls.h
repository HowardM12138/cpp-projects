#ifndef LS_H
#define LS_H

#include <iostream>

void ls(std::string options = "");
bool get_option(std::string &options);
void long_list_output();
void short_list_output();
void reset();

#endif
