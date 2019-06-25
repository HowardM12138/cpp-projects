#ifndef KEY_PRESS_H
#define KEY_PRESS_H

#include <termios.h>
#include <iostream>

const int KEY_ENTER = 138;
const int KEY_TAB = 137;
const int KEY_UP = 183;
const int KEY_DOWN = 184;
const int KEY_RIGHT = 185;
const int KEY_LEFT = 186;
const int KEY_DEL = 255;
const int KEY_HOME = 190;
const int KEY_END = 188;
const int KEY_PAGE_UP = 171;
const int KEY_PAGE_DOWN = 172;
const int ASCII_CHAR_RANGE = 126;

static struct termios old, New;

void initTermios(int echo);
void resetTermios(void);
char getch_(int echo);
char getch(void);
char getche(void);
int get_key_pressed();

/* Initialize New terminal i/o settings */

void initTermios(int echo)
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  New = old; /* make new settings same as old settings */
  New.c_lflag &= ~ICANON; /* disable buffered i/o */
  if (echo) {
      New.c_lflag |= ECHO; /* set echo mode */
  } else {
      New.c_lflag &= ~ECHO; /* set no echo mode */
  }
  tcsetattr(0, TCSANOW, &New); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void)
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo)
{
  char ch;
  initTermios(echo);
  ch = std::cin.get();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void)
{
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void)
{
  return getch_(1);
}

//Modified Code
int get_key_pressed()
{
    char c;
    c = getch();
    if (c == 27 && getch() == 91) {
        c = getch();
        switch (c) {
            case 65:
                return KEY_UP;
            case 66:
                return KEY_DOWN;
            case 67:
                return KEY_RIGHT;
            case 68:
                return KEY_LEFT;
            case 72:
                return KEY_HOME;
            case 70:
                return KEY_END;
            case 53:
                c = getch();
                return KEY_PAGE_UP;
            case 54:
                c = getch();
                return KEY_PAGE_DOWN;
            default:
                std::cout << "Error in arrow key section: " << c << "\n";
                return -1;
        }
    } else if (c == 10) {
        return KEY_ENTER;
    } else if (c == 9) {
        return KEY_TAB;
    } else if (c == 127){
        return KEY_DEL;
    }else {
        return static_cast<int>(c);
    }
    return -1;
}

std::string get_key_pressed_str(int c) {
    if (c < 128) {
        std::string s(1, static_cast<char>(c));
        return s;
    } else {
        switch (c) {
            case KEY_UP:
                return "Up arrow key";
            case KEY_DOWN:
                return "Down arrow key";
            case KEY_RIGHT:
                return "Right arrow key";
            case KEY_LEFT:
                return "Left arrow key";
            case KEY_ENTER:
                return "ENTER";
            case KEY_TAB:
                return "TAB";
            case KEY_DEL:
                return "DEL";
            case KEY_HOME:
                return "HOME";
            case KEY_END:
                return "END";
            case KEY_PAGE_UP:
                return "PAGE UP";
            case KEY_PAGE_DOWN:
                return "PAGE DOWN";
            default:
                return "Unrecognized key input.";
        }
    }
}

#endif
