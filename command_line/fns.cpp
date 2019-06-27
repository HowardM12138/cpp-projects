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
    } else if (command.str.substr(0,2) == "ls"){
        std::string options = command.str.substr(2);
        ls(options);
    } else if (command.str == "pwd") {
        std::cout << getcwd(str_directory, 4096) << "\n";
    } else if (command.str.substr(0,5) == "echo ") {
        std::cout << command.str.substr(5) << "\n";
    } else if (command.str.substr(0,4) == "g++ ") {
        gcc(get_file_names_from_str(command.str.substr(4)));
    } else if (command.str[0] == '.' || command.str[0] == '/') {
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

void gcc(std::vector<std::string> files) {
    if (files.size() == 0) return;
    for (int i = 0; i < files.size(); i++) {
        if (is_valid_file_name(files[i], ".cpp"))
            std::cout << "compiled " << files[i] << "\n";
        else
            std::cout << "error: \"" << files[i] << "\" is not a valid file name\n";
    }
}

void execute(std::string str) {
    pid_t pid = fork();

    if (pid == -1) {
        std::cout << "failed\n";
    }
    if (pid == 0) {
        std::cout << "child processing\n";
        if (execl(str.c_str(), "", NULL) == -1) {
            std::cout << "error: The file doesn't exist\n";
            exit(0);
        }
    }
    if (pid > 0) {
        wait(0);
        std::cout << "parent processing\n";
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
