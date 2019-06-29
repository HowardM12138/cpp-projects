#include "fns.h"
#include "../my_library/key_press.h"

bool insertion_mode = false;
std::vector<Line> lines;

void start() {
    user_input();
}

void user_input() {
    std::string trail = "";
    std::string str = "";
    int index = -1;
    while (1) {
        str = "";
        index = index + 1;
        Line line = {str, index};
        lines.insert(lines.begin() + index, line);
        int c;
        do {
            c = get_key_pressed();
            if (c == KEY_INSERT) {
                insertion_mode = insertion_mode ? false : true;
            } else if (insertion_mode) {
                process_char_input(c, line, trail);
                std::cout << trail;
                for (int i = 0; i < trail.size(); i++) {
                    std::cout << "\b";
                }
            }
        } while (c != KEY_ENTER);
        if (!insertion_mode) {
            exit(0);
        }
        lines.erase(lines.begin() + index);
        lines.insert(lines.begin() + index, line);
        std::cout << lines.size();

        for (int i = 0; i < trail.size(); i++) std::cout << " ";
        for (int i = 0; i < trail.size(); i++) std::cout << "\b";
        std::cout << "\n";
        int j = index + 1;
        if (j < lines.size()) {
            for (int i = 0; i < lines[j].str.size(); i++) std::cout << " ";
            for (int i = 0; i < lines[j].str.size(); i++) std::cout << "\b";
        }
        std::cout << trail << "\r";

        /*
        for (int i = 0; i < trail.size(); i++) std::cout << " ";
        for (int i = 0; i < trail.size(); i++) std::cout << "\b";
        std::cout << "\n";
        int j = index + 1;
        if (j < lines.size()) {
            for (int i = 0; i < lines[j].size(); i++) std::cout << " ";
            for (int i = 0; i < lines[j].size(); i++) std::cout << "\b";
        }
        std::cout << trail << "\n";
        int counter = 0;
        for (int i = index + 1; i < lines.size(); i++) {
            std::cout << lines[i] << "\n";
            counter += 1;
        }
        std::cout << "\r";
        for (int i = 0; i < counter + 1; i++) std::cout << "\x1b[A";
        //if (index != lines.size()) lines.erase(lines.begin() + index);
        lines.insert(lines.begin() + index, str);
        lines.insert(lines.begin() + index + 1, str);
        */
    }
}

void process_char_input (int c, Line &line, std::string trail) {
    if (c == KEY_ENTER) return;
    if (c <= ASCII_CHAR_RANGE) {
        //Display key pressed onto the screen
        char character = static_cast<char>(c);
        line.str += character;
        std::cout << character;
    } else if (c == KEY_DEL && line.str.size() > 0) {
        //Deletes the last character
        std::cout << "\b";
        for (int i = 0; i < trail.size() + 1; i++) std::cout << " ";
        for (int i = 0; i < trail.size() + 1; i++) std::cout << "\b";
        line.str = line.str.substr(0, line.str.size() - 1);
    } else if (c == KEY_LEFT && line.str.size() > 0){
        //Moves the insertion point one character to the Left
        trail = line.str.substr(line.str.size()-1) + trail;
        line.str = line.str.substr(0, line.str.size() - 1);
        std::cout << "\b";
    } else if (c == KEY_RIGHT && trail.size() > 0) {
        //Moves the insertion point one character to the Right
        line.str = line.str + trail.substr(0,1);
        trail = trail.substr(1);
        std::cout << line.str.substr(line.str.size() - 1);
    } else if (c == KEY_UP && line.index > 0) {
        //Move up a command line from history
        int i = line.str.size();
        trail = line.str.substr(0, i) + trail;
        int j = line.index;
        line = lines[line.index - 1];
        lines.erase(lines.begin() + j);
        if (i < line.str.size()) {
            trail = line.str.substr(i) + trail;
        }
        std::cout << "\x1b[A";
        /*
        int i = str.size();
        str += trail;
        if (index != lines.size()) lines.erase(lines.begin() + index);
        lines.insert(lines.begin() + index, str);
        index = index - 1;
        str = lines[index];
        if (i < str.size()) {
            trail = str.substr(i);
            str = str.substr(0, i);
        }
        std::cout << "\x1b[A";
        */
    } else if (c == KEY_DOWN && line.index < 0) {
        //Move down a command line from history

    } else if (c == KEY_HOME) {
        trail = line.str + trail;
        for (int i = 0; i < line.str.size(); i++) std::cout << "\b";
        line.str.clear();
    } else if (c == KEY_END) {
        std::cout << trail;
        line.str = line.str + trail;
        trail.clear();
    }
}
