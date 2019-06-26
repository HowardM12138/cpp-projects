#include "../my_library/key_press.h"
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <iomanip>

int main() {

    /*
    while (1) {
        std::cout << "You pressed: " << get_key_pressed_str(get_key_pressed()) << "\n";
    }
    */

    DIR *directory;
    char str_directory[4096];
    char file_path[4096];
    struct dirent *file;
    struct stat status;
    struct passwd *user;
    struct group *group;


    getcwd(str_directory, 4096);
    directory = opendir(str_directory);

    while ((file = readdir(directory)) != NULL) {

        sprintf(file_path, "%s/%s", str_directory, file->d_name);
        stat(file_path, &status);

        switch(status.st_mode & S_IFMT) {
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

        std::cout << ((status.st_mode & S_IRUSR) ? "r" : "-");
        std::cout << ((status.st_mode & S_IWUSR) ? "w" : "-");
        std::cout << ((status.st_mode & S_IXUSR) ? "x" : "-");
        std::cout << ((status.st_mode & S_IRGRP) ? "r" : "-");
        std::cout << ((status.st_mode & S_IWGRP) ? "w" : "-");
        std::cout << ((status.st_mode & S_IXGRP) ? "x" : "-");
        std::cout << ((status.st_mode & S_IROTH) ? "r" : "-");
        std::cout << ((status.st_mode & S_IWOTH) ? "W" : "-");
        std::cout << ((status.st_mode & S_IXOTH) ? "x " : "- ");

        std::cout << status.st_nlink << " ";

        user = getpwuid(status.st_uid);
        std::cout << user->pw_name << " ";

        group = getgrgid(status.st_gid);
        std::cout << group->gr_name << " ";

        std::cout << std::right << std::setw(5) <<status.st_size << " ";

        char date [36];
        strftime(date, 36, "%b %d %H:%M", localtime(&status.st_mtime));
        std::cout << std::setw(12) << date << " ";

        std::cout << file->d_name << "\n";
    }
    closedir(directory);
}
