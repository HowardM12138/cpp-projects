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
                process_char_input(c, str, trail);

                std::cout << trail;
                std::cout << "\x1b[" << y << ";" << x << "H";
            }
        } while (c != KEY_ENTER);

        if (!insertion_mode) {
            exit(0);
        }

        for (int i = 0; i < trail.size(); i++) {
            if (trail[i] != '\n') std::cout << " ";
            else std::cout << "\n";
        }
        x = 1;
        ++y;
        std::cout << "\x1b[" << y << ";" << x << "H";

        str += "\n";

        std::cout << trail;
        std::cout << "\x1b[" << y << ";" << x << "H";
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
            str += "\n";
            std::cout << "\n";
        }
    } else if (c == KEY_DEL) {
        //Deletes the last character
        if (x != 1) {
            str = str.substr(0, str.size() - 1);
            --x;
            std::cout << "\b";
            for (int i = 0; i < trail.size() + 1; i++) std::cout << " ";
            std::cout << "\x1b[" << y << ";" << x << "H";
        } else if (y != 1){
            str = str.substr(0, str.size() - 1);
            int length;
            if (y == 2) {
                length = str.size();
            }
            if (y > 2) {
                length = str.substr(str.find_last_of('\n') + 1).size();
            }

            x = length;
            --y;

            if (x != size_x) ++x;
            std::cout << "\x1b[" << y << ";" << x << "H";
            std::cout << " ";
            std::cout << "\x1b[" << y << ";" << x << "H";

            if (length == size_x) str = str.substr(0, str.size() - 1);
        }
    } else if (c == KEY_LEFT){
        //Moves the insertion point one character to the Left
        if (x != 1) {
            --x;
            trail = str.substr(str.size() - 1) + trail;
            str = str.substr(0, str.size() - 1);
            std::cout << "\b";
        } else if (y != 1) {
            trail = str.substr(str.size() - 1) + trail;
            str = str.substr(0, str.size() - 1);

            std::string temp = str.substr(0, str.size());
            int length;
            if (y == 2) {
                length = temp.size();
            }
            if (y > 2) {
                length = temp.substr(temp.find_last_of('\n') + 1).size();
            }

            x = length;
            --y;

            if (x != size_x) ++x;
            else {
                trail = str.substr(str.size() - 1) + trail;
                str = str.substr(0, str.size() - 1);
            }
            std::cout << "\x1b[" << y << ";" << x << "H";
        }
    } else if (c == KEY_RIGHT) {
        //Moves the insertion point one character to the Right
        /*
        str = str + trail.substr(0,1);
        trail = trail.substr(1);
        std::cout << str.substr(str.size() - 1);
        */
    } else if (c == KEY_UP && y > 0) {
        //Move up a command line from history
        /*
        int i = str.size();
        trail = str.substr(0, i) + trail;
        int j = line_index;
        line = lines[line_index - 1];
        lines.erase(lines.begin() + j);
        if (i < str.size()) {
            trail = str.substr(i) + trail;
        }
        std::cout << "\x1b[A";

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
    } else if (c == KEY_DOWN && y < 0) {
        //Move down a command line from history

    } else if (c == KEY_HOME) {
        /*
        trail = str + trail;
        for (int i = 0; i < str.size(); i++) std::cout << "\b";
        str.clear();
        */
    } else if (c == KEY_END) {
        /*
        std::cout << trail;
        str = str + trail;
        trail.clear();
        */
    }
}

void move_cursor_up(std::string &str) {

}
