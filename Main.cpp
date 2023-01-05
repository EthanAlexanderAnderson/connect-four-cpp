// Singleplayer Connect-four in C++
// By Ethan Anderson

#include <stdlib.h>
#include <iostream>
#include <ctime>

void printBoard(char board[][7]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++){
            std::cout << board[i][j];
        }
        std::cout << "\n";
    }
}

void dropChip(char board[][7], int turn, int selected) {
    for (int i = 6; i >= 0; i--) {
        if (board[i][selected] == '_') {
            if ( turn == 0) {
                board[i][selected] = 'O';
                return;
            } else {
                board[i][selected] = 'X';
                return;
            }
        }
    }
}

int main() {

    // Initialize variables
    char board [7][7]; // [row] [column]
    int selected = 0;
    int turn = 0; // 0 = player, 1 = CPU
    std::srand( std::time(0) );

    // Fill board with empty symbols
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++){
            board[i][j] = '_';
        }
    }

    // Startup and welcome
    std::cout << "Hello welcome to connect-four.\n";

    printBoard(board);

    std::cout << "Choose column to drop chip (0-6): ";
    std::cin >> selected;

    dropChip(board, turn, selected);

    printBoard(board);

    return 0;
}