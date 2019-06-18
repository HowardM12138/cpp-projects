#ifndef FNS_H
#define FNS_H

void start();
bool restart();
void end();
int get_random_number(int min, int max);
bool user_guess(int tries, int answer);
bool win();
void lose(int answer);

#endif
