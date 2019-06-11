#ifndef FNS_H
#define FNS_H

#include <typeinfo>
#include <iostream>

bool valid_move(int** board, int row, int col, int size);
void print_board (int** board, int size);
void get_solution_chess_boards(int** board, int num_of_total_queens, int num_of_placed_queens = 0);
bool solution_exist();

#endif
