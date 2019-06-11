#include "fns.h"
#include <iostream>

int main() {

    int num_of_total_queens = 0;
    std::cout << "Enter the number of queens: ";
    std::cin >> num_of_total_queens;
    std::cout << "\n";

    const int N = num_of_total_queens;
    int** board = new int*[N];      //initialize pointers for rows
    for(int i = 0; i < N; i++)
        board[i] = new int[N];      //initialize pointers for columns
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; ++j)
            board[i][j] = 0;

    get_solution_chess_boards(board, num_of_total_queens);

    return 0;
}
