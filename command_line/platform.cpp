#include "class.h"
#include "platform.h"
#include "fns.h"
#include "../my_library/key_press.h"

#include <iostream>
#include <vector>

const std::string COMMAND_HEADER = "C:\\WINDOWS\\system32>~$ ";
Command_Line_Status status = OFF;
std::vector<Command> history;

void user_input() {
    while (status == ON) {
        //init variables to get user input
        Command command = {"", "", history.size()};
        std::string trail = "";
        int c;

        save_command(command);

        std::cout << COMMAND_HEADER;

        do {
            c = get_key_pressed();
            //process input charawcter
            process_char_input(c, command, trail);
            //Prints out trail string
            if (trail.size() != 0) {
                std::cout << trail;
                for (int i = 0; i < trail.size(); i++) std::cout << "\b";
            }
        } while (c != KEY_ENTER);
        //Save command and operate command
        command.str += trail;
        std::cout << "\n";
        save_new_command(command);
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
        //Move up a command line from history
        command.str += trail;
        trail = "";
        save_command(command);
        erase_line(command.str.size());
        command = history[command.index - 1];
        std::cout << command.str;
    } else if (c == KEY_DOWN && command.index < history.size() - 1) {
        //Move down a command line from history
        command.str += trail;
        trail = "";
        save_command(command);
        erase_line(command.str.size());
        command = history[command.index + 1];
        std::cout << command.str;
    } else if (c == KEY_HOME) {
        trail = command.str + trail;
        for (int i = 0; i < command.str.size(); i++) std::cout << "\b";
        command.str.clear();
    } else if (c == KEY_END) {
        std::cout << trail;
        command.str = command.str + trail;
        trail.clear();
    }
}

void erase_line(int size) {
    for (int i = 0; i < size + COMMAND_HEADER.size(); i++) std::cout << "\b";
    for (int i = 0; i < size + COMMAND_HEADER.size(); i++) std::cout << " ";
    for (int i = 0; i < size + COMMAND_HEADER.size(); i++) std::cout << "\b";
    std::cout << COMMAND_HEADER;
}

void save_command(Command &command) {
    if (command.index != history.size()) history.erase(history.begin() + command.index);
    history.insert(history.begin() + command.index, command);
}

void save_new_command(Command &command) {
    if (command.index != history.size() - 1) {
        std::string temp = command.str;
        command.str = command.command;
        save_command(command);
        command.index = history.size() - 1;
        command.str = temp;
    }
    command.command = command.str;
    save_command(command);
}
