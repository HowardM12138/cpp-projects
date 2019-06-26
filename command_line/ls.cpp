#include "ls.h"

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

bool _a = false;
bool _l = false;

DIR *directory;
char str_directory[4096];
char file_path[4096];
struct dirent *file;
struct stat stats;
struct passwd *user;
struct group *group;

void ls(std::string options) {
    getcwd(str_directory, 4096);
    directory = opendir(str_directory);

    if (get_option(options)) {
        while ((file = readdir(directory)) != NULL) {
            sprintf(file_path, "%s/%s", str_directory, file->d_name);
            stat(file_path, &stats);

            if (!_a) {
                if ((stats.st_mode & S_IFMT) != S_IFREG) continue;
                if (_l) long_list_output();
                else short_list_output();
            } else {
                if (_l) long_list_output();
                else short_list_output();
            }
        }
    } else std::cout << "error: Invalid command\n";

    reset();
}

bool get_option(std::string &options) {
    if (options == "") return true;

    if (options.substr(0,2) != " -") return false;
    options = options.substr(2);
    for (int i = 0; i < options.size(); i++) {
        switch (options[i]) {
            case 'a':
                _a = true;
                break;
            case 'l':
                _l = true;
                break;
            default:
                return false;
        }
    }
    return true;
}

void long_list_output() {


    switch(stats.st_mode & S_IFMT) {
        case S_IFREG:
            std::cout << "-";
            break;
        case S_IFDIR:
            std::cout << "d";
            break;
        case S_IFLNK:
            std::cout << "l";
            break;
    }

    std::cout << ((stats.st_mode & S_IRUSR) ? "r" : "-");
    std::cout << ((stats.st_mode & S_IWUSR) ? "w" : "-");
    std::cout << ((stats.st_mode & S_IXUSR) ? "x" : "-");
    std::cout << ((stats.st_mode & S_IRGRP) ? "r" : "-");
    std::cout << ((stats.st_mode & S_IWGRP) ? "w" : "-");
    std::cout << ((stats.st_mode & S_IXGRP) ? "x" : "-");
    std::cout << ((stats.st_mode & S_IROTH) ? "r" : "-");
    std::cout << ((stats.st_mode & S_IWOTH) ? "w" : "-");
    std::cout << ((stats.st_mode & S_IXOTH) ? "x " : "- ");

    std::cout << stats.st_nlink << " ";

    user = getpwuid(stats.st_uid);
    std::cout << user->pw_name << " ";

    group = getgrgid(stats.st_gid);
    std::cout << group->gr_name << " ";

    std::cout << std::setw(5) <<stats.st_size << " ";

    char date [36];
    strftime(date, 36, "%b %d %H:%M", localtime(&stats.st_mtime));
    std::cout << std::setw(12) << date << " ";

    std::cout << file->d_name << "\n";
}

void short_list_output() {
    std::cout << file->d_name << "\n";
}

void reset() {
    _a = false;
    _l = false;
}
