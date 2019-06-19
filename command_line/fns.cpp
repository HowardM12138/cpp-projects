#include "fns.h"
#include "command_line.h"
#include <iostream>
#include <vector>

std::vector<std::string> history;
Command_Line_Status status = OFF;


void rebuild() {
    history.clear();
    status = ON;
    std::cout << "\nCommand line operating.\n";
}

void end() {
    std::cout << "Command line terminates.\n";
    status = OFF;
}

void user_input() {
    while (status == ON) {
        std::string command;
        std::cout << "~$ ";
        std::cin >> command;
        operate(command);
    }
}

void operate(std::string command) {
    history.push_back(command);

    if (command == "shutdown") {
        end();
    } else if (command == "show_history") {
        print_command_history();
    } else if (command == "restart") {
        rebuild();
    }
}

void print_command_history() {
    for (int i = 0; i < history.size(); i++) {
        std::cout << i+1 << ". " << history[i] << "\n";
    }
}
