#include "fns.h"

std::vector<std::string> errors;

void process_command(Command &command) {
    if (command.str == "shutdown") {
        end();
    } else if (command.str == "reboot") {
        reboot();
    } else if (command.str == "history") {
        if (history.size() > 1 && history[command.index - 1].command == "history")
            history.pop_back();
        print_command_history();
    } else if (command.str.substr(0,3) == "cd "){
        cd((command.str.substr(3)));
    } else if (command.str.substr(0,6) == "mkdir ") {
        if (mkdir(command.str.substr(6).c_str(), 0777) == -1)
            std::cout << "error: Failed to make directory\n";
    } else if (command.str.substr(0,6) == "rmdir ") {
        if (rmdir(command.str.substr(6).c_str()) == -1)
            std::cout << "error: Failed to remove directory\n";
    } else if (command.str.substr(0,3) == "rm ") {
        if (remove(command.str.substr(3).c_str()) == -1)
            std::cerr << "Error :  " << std::strerror(errno) << std::endl;
    } else if (command.str.substr(0,6) == "touch ") {
        touch(command.str.substr(6));
    } else if (command.str.substr(0,2) == "ls"){
        std::string options = command.str.substr(2);
        ls(options);
    } else if (command.str == "pwd") {
        std::cout << getcwd(str_directory, 4096) << "\n";
    } else if (command.str.substr(0,5) == "echo ") {
        std::cout << command.str.substr(5) << "\n";
    } else if (command.str.substr(0,4) == "g++ ") {
        gcc(command.str);
    } else if (command.str[0] == '.' && command.str[1] == '/') {
        execute(command.str);
    } else {
        errors.push_back("Invalid command");
    }
    print_errors();
    errors.clear();
}

//Functional methods
void end() {
    status = OFF;
}

void reboot() {
    history.clear();
    std::cout << "\n\033[1;92mrebooting...\033[0m\n\n";
}

void print_command_history() {
    std::cout << "\n";
    for (int i = 0; i < history.size(); i++)
        std::cout << std::setw(5) << i+1 << "  " << history[i].command << "\n";
    std::cout << "\n";
}

void cd(std::string path) {
    if (chdir(path.c_str()) != -1) {
        getcwd(str_directory, 4096);
        directory = opendir(str_directory);
        COMMAND_HEADER = "\033[1;92mbingxu:\033[1;34m";
        COMMAND_HEADER += str_directory;
        COMMAND_HEADER += "\033[0m~$ ";
    } else std::cout << "error: Invalid directory\n";
}

void touch(std::string file_name) {
    std::fstream file;
    file.open (file_name.c_str(), std::ios::out);
    file.close();
}

void gcc(std::string str) {
    pid_t pid = fork();

    if (pid == -1) {
        std::cout << "error: Forking failed\n";
    }
    if (pid == 0) {
        system(str.c_str());
        exit(0);
    }
    if (pid > 0) {
        wait(0);
    }
}

void execute(std::string str) {
    pid_t pid = fork();

    if (pid == -1) {
        std::cout << "error: Forking failed\n";
    }
    if (pid == 0) {
        if (execlp(str.c_str(), "", NULL) == -1) {
            std::cout << "error: The file doesn't exist\n";
            exit(0);
        }
    }
    if (pid > 0) {
        wait(0);
    }
}

void print_errors() {
    for (int i = 0; i < errors.size(); i++) {
        std::cout << "error: " << errors[i] << "\n";
    }
}


//Helper functions
std::vector<std::string> get_file_names_from_str(std::string str) {
    std::vector<std::string> file_names;
    str += " ";
    while (str.find_first_of(' ') != std::string::npos) {
        std::string file = str.substr(0, str.find_first_of(' '));
        str = str.substr(str.find_first_of(' ') + 1);
        file_names.push_back(file);
    }
    return file_names;
}

bool is_valid_file_name(std::string str, std::string extension) {
    std::string file_name = str.substr(0, str.size() - extension.size());
    std::string file_extension = str.substr(str.size() - extension.size());

    for (int i = 0; i < file_name.size(); i++) {
        char c = file_name[i];
        if (!(c >= 48 && c <= 57 ||
            c >= 65 && c <= 90 ||
            c >= 97 && c <= 122 ||
            c == 45 ||
            c == 95 ||
            c == 46)) return false;
    }

    if (file_extension != extension) return false;

    return true;
}
