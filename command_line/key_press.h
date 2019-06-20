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
            default:
              std::cout << "Error in arrow key section.\n";
              return -1;
        }
    } else if (c == 10) {
        return KEY_ENTER;
    } else if (c == 9) {
        return KEY_TAB;
    } else {
        return static_cast<int>(c);
    }
    return -1;
}

void display_key_pressed(int c) {
    if (c < 128) std::cout << static_cast<char>(c) << "\n";
    else {
        switch (c) {
            case KEY_UP:
                std::cout << "Up arrow key.\n";
                break;
            case KEY_DOWN:
                std::cout << "Down arrow key.\n";
                break;
            case KEY_RIGHT:
                std::cout << "Right arrow key.\n";
                break;
            case KEY_LEFT:
                std::cout << "Left arrow key.\n";
                break;
            case KEY_ENTER:
                std::cout << "ENTER.\n";
                break;
            case KEY_TAB:
                std::cout << "TAB.\n";
                break;
        }
    }
}
#endif
