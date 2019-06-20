#include "fns.h"
#include "command_line.h"
#include "../my_library/key_press.h"
#include <iostream>
#include <istream>
#include <vector>

std::vector<Command> history;
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
        //init variables to get user input
        Command command = {"", history.size(), false};  //Holds the entered command from the user
        std::string trail = "";                         //Holds the trail of string after the insertion point
        int c;                                          //Holds key board inter, which return as an int

        std::cout << "~$ ";

        do {
            c = get_key_pressed();

            process_char_input(c, command, trail);
            //add command object

            //Prints out trail string
            if (trail.size() != 0) {
                std::cout << trail;
                for (int i = 0; i < trail.size(); i++) std::cout << "\b";
            }
        } while (c != KEY_ENTER);
        //operates command afterwards
        std::cout << "\n";
        process_command(command);
    }
}

void process_char_input(int c, Command &command, std::string &trail) {
    if (c <= ASCII_CHAR_RANGE) {
        //Display key pressed onto the screen
        char character = static_cast<char>(c);
        command.str += character;
        std::cout << character;
    } else if (c == KEY_DEL && command.str.size () > 0) {
        //Deletes a character on the current command line
        std::cout << "\b";
        for (int i = 0; i < trail.size()+1; i++) std::cout << " ";
        for (int i = 0; i < trail.size()+1; i++) std::cout << "\b";
        command.str = command.str.substr(0, command.str.size() - 1);
    } else if (c == KEY_LEFT && command.str.size() > 0){
        //Moves the insertion point one character to the Left
        trail = command.str.substr(command.str.size()-1) + trail;
        command.str = command.str.substr(0, command.str.size() - 1);
        std::cout << "\b";
    } else if (c == KEY_RIGHT && trail.size() > 0) {
        //Moves the insertion point one character to the Right
        command.str = command.str + trail.substr(0,1);
        trail = trail.substr(1);
        std::cout <<command.str.substr(command.str.size() - 1);
    } else if (c == KEY_UP && command.index > 0) {
        history.push_back(command);
        trail = "";
        command = history[command.index - 1];
        std::cout << command.str;
    }
}

void process_command(Command &command) {
    history.push_back(command);

    if (command.str == "shutdown") {
        end();
    } else if (command.str == "show history") {
        print_command_history();
    } else if (command.str == "restart") {
        rebuild();
    }
}

void print_command_history() {
    for (int i = 0; i < history.size(); i++) {
        std::cout << i+1 << ". " << history[i].str << "\n";
    }
}
