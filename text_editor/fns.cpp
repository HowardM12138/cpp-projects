#include "fns.h"
#include "../my_library/key_press.h"

int y = 1;
int x = 1;
int size_x;
int size_y;

void start() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    size_x = w.ws_col;
    size_y = w.ws_row;
    std::cout << "\x1b[2J";
    std::cout << "\x1b[" << y << ";" << x << "H";
    user_input();
}

void user_input() {
    bool insertion_mode = false;

    std::string trail = "";
    std::string str = "";

    while (1) {
        int c;
        do {
            c = get_key_pressed();
            if (c == KEY_INSERT) {
                insertion_mode = insertion_mode ? false : true;
            } else if (insertion_mode) {
                std::cout << "\x1b[" << y << ";" << x << "H";
                process_char_input(c, str, trail);
                std::cout << trail;
                std::cout << "\x1b[" << y << ";" << x << "H";
            }
        } while (c != KEY_ENTER);

        if (!insertion_mode) {
            exit(0);
        }

        erase_trail(trail);

        x = 1;
        ++y;
        std::cout << "\x1b[" << y << ";" << x << "H";
        std::cout << trail;
        std::cout << "\x1b[" << y << ";" << x << "H";

        str += "\n";
    }
}

void process_char_input (int c, std::string &str, std::string &trail) {
    if (c == KEY_ENTER) return;
    if (c <= ASCII_CHAR_RANGE) {
        //Display key pressed onto the screen
        char character = static_cast<char>(c);
        str += character;
        std::cout << character;
        ++x;
        if (x == size_x+1) {
            x = 1;
            ++y;
            std::cout << "\x1b[" << y << ";" << x << "H";
        }
    } else if (c == KEY_DEL && str.size() > 0) {
        //Deletes the last character
        erase_trail(trail);
        if (x == 1){
            move_cursor_back_a_line(str);
        } else {
            std::cout << "\b";
            --x;
        }
        std::cout << " \b";
        str = str.substr(0, str.size() - 1);
        std::cout << trail;
        std::cout << "\x1b[" << y << ";" << x << "H";
    } else if (c == KEY_LEFT && str.size() > 0) {
        //Moves the insertion point one character to the Left
        if (x == 1) {
            move_cursor_back_a_line(str);
        } else {
            std::cout << "\b";
            --x;
        }
        trail = str.substr(str.size() - 1) + trail;
        str = str.substr(0, str.size() - 1);
    } else if (c == KEY_RIGHT && trail.size() > 0) {
        //Moves the insertion point one character to the Right
        if (x == 80 || trail[0] == '\n') {
            x = 1;
            ++y;
            std::cout << "\x1b[" << y << ";" << x << "H";
        } else {
            ++x;
            std::cout << trail[0];
        }
        str += trail[0];
        trail = trail.substr(1);
    } else if (c == KEY_UP && y > 0) {
        
    } else if (c == KEY_DOWN && y < 0) {

    } else if (c == KEY_HOME) {

    } else if (c == KEY_END) {

    }
}

void move_cursor_back_a_line(std::string &str) {
    std::string last_line = get_last_line(str);
    int size = last_line.size();
    if (size > size_x) {
        size = size % size_x;
    }
    if (size == 0) size = size_x;
    x = size;
    --y;
    std::cout << "\x1b[" << y << ";" << x << "H";
}

void erase_trail(std::string &trail) {
    for (int i = 0; i < trail.size(); i++) {
        if (trail[i] != '\n') std::cout << " ";
        else std::cout << '\n';
    }
    std::cout << "\x1b[" << y << ";" << x << "H";
}

std::string get_last_line(std::string str) {
    std::string temp = str;
    if (str[str.size() - 1] == '\n') temp = temp.substr(0, str.size() - 1);
    int index = -1;
    if (temp.find_last_of('\n') != std::string::npos) index = temp.find_last_of('\n');
    return str.substr(index + 1);
}
