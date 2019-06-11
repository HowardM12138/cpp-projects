#include "fns.h"
#include <iostream>

int solution_count = 0;
bool has_solution = false;

bool valid_move(int** board, int row, int col, int size) {
    //Checks for if same piece exist in the same column
    for (int i = 0; i < size; i++) {
        if (i == row) continue;
        if (board[i][col] == 1) return false;
    }
    //Checks for if same piece exist in the same row
    for (int j = 0; j < size; j++) {
        if (j == col) continue;
        if (board[row][j] == 1) return false;
    }
    //Checks for if same piece exist diagonally
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            if (x - y == row - col || x - (size - y) == row - (size - col)) {
                if (x == row && y == col) continue;
                if (board[x][y] == 1) return false;
            }
        }
    }
    return true;
}

void get_solution_chess_boards(int** board, int num_of_total_queens, int num_of_placed_queens) {
    if (num_of_total_queens == num_of_placed_queens) {
        //print a solution board when recursion reaches the end
        has_solution = true;
        solution_count++;
        std::cout << "Solution: " << solution_count << "\n";
        print_board(board, num_of_total_queens);
    } else {
        //Loops through the next column recursively
        for (int i = 0; i < num_of_total_queens; i++) {
            if (valid_move(board, i, num_of_placed_queens, num_of_total_queens)) {
                board[i][num_of_placed_queens] = 1;
                //recursion function call to next column
                get_solution_chess_boards(board, num_of_total_queens, num_of_placed_queens + 1);
                //backtracking statement
                board[i][num_of_placed_queens] = 0;
            }
        }
    }
}

void print_board (int** board, int size) {
    //Prints a formatted board configuraion
    for (int i = 0; i < size * 2; i++) {
        for (int j = 0; j < size; j++) {
            if (i % 2 == 0) {
                std::cout << "--";
                if (j == size - 1) std::cout << "-";
            } else {
                std::cout << "|";
                if (board[i/2][j] == 1) std::cout << "x";
                else std::cout << " ";
                if (j == size - 1) std::cout << "|";
            }
        }
        std::cout << "\n";
    }
    for (int i = 0; i < size; i++) {
        std::cout << "--";
        if (i == size - 1) std::cout << "-";
    }
    std::cout << "\n\n";
}

bool solution_exist() {
    return has_solution;
}
