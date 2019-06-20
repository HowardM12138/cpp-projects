#include "fns.h"
#include "command_line.h"
#include "key_press.h"
#include <iostream>
#include <istream>
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
        //std::cout << std::cin.tellg() << "\n";
        //command = std::cin.get();
        int c;
        char character;
        std::string trail = "";
        do {
            c = get_key_pressed();
            //display_key_pressed(c);
            if (c < 127) {
                character = static_cast<char>(c);
                command += character;
                std::cout << character;
            } else if (c == 127 && command.size () > 0) {
                delete_char(command);
            } else if (c == KEY_LEFT){
                trail = command.substr(command.size()-1) + trail;
                command = command.substr(0, command.size() - 1);
                std::cout << "\b";
            } else if (c == KEY_RIGHT) {
                command = command + trail.substr(0,1);
                trail = trail.substr(1);
                std::cout <<command.substr(command.size() - 1);
            }
            if (trail.size() != 0) {
                std::cout << trail;
                for (int i = 0; i < trail.size(); i++) std::cout << "\b";
            }
        } while (c != KEY_ENTER);
        std::cout << "\n";
        operate(command);
    }
}

void operate(std::string command) {
    history.push_back(command);

    if (command == "shutdown") {
        end();
    } else if (command == "show history") {
        print_command_history();
    } else if (command == "restart") {
        rebuild();
    }
}

void delete_char(std::string &str) {
    std::cout << "\b \b";
    str = str.substr(0, str.size() - 1);
}

void print_command_history() {
    for (int i = 0; i < history.size(); i++) {
        std::cout << i+1 << ". " << history[i] << "\n";
    }
}
