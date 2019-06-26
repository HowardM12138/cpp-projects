#ifndef LS_H
#define LS_H

#include "platform.h"

#include <iostream>
#include <iostream>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <iomanip>

void ls(std::string options = "");
bool get_option(std::string &options);
void long_list_output();
void short_list_output();
void reset();

#endif
