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

int main() {

    // Initialize variables
    char board [7][7]; // [row] [column]

    // Fill board with empty symbols
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++){
            board[i][j] = '_';
        }
    }

    // Startup and welcome
    std::cout << "Hello welcome to connect-four.\n";

    printBoard(board);

    return 0;
}