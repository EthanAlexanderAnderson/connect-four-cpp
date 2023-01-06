// Singleplayer Connect-four in C++
// By Ethan Anderson

#include <stdlib.h>
#include <iostream>
#include <ctime>

void printBoard(char board[][7]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++){
            std::cout << board[i][j];
            std::cout << " ";
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

void undoDrop(char board[][7], int selected) {
    for (int i = 0; i < 7; i++) {
        if (board[i][selected] == 'O' || board[i][selected] == 'X') {
            board[i][selected] = '_';
            return;
        }
    }
}

int swapTurn(int turn) {
    if (turn == 0) {
        return 1;
    } else {
        return 0;
    }
}

int winCheck(char board[][7]) {
    // Counters for chips in a row
    int Xc = 0;
    int Oc = 0; 

    // check horizontal win
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++){
            if (board[i][j] == 'O') {
                Oc++;
                Xc = 0;
                if (Oc == 4) {
                    return 0;
                }
            } else if (board[i][j] == 'X') {
                Xc++;
                Oc = 0;
                if (Xc == 4) {
                    return 1;
                }
            } else {
                Oc = 0;
                Xc = 0;
            }
        }
        Oc = 0;
        Xc = 0;
    }

    // check vertical win
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++){
            if (board[j][i] == 'O') {
                Oc++;
                Xc = 0;
                if (Oc == 4) {
                    return 0;
                }
            } else if (board[j][i] == 'X') {
                Xc++;
                Oc = 0;
                if (Xc == 4) {
                    return 1;
                }
            } else {
                Oc = 0;
                Xc = 0;
            }
        }
        Oc = 0;
        Xc = 0;
    }
    // Check descending diagonal win
    for (int n = 0; n < 7; n++) {
        //std::cout << "\n";
        int i = 3 - n;
        int j = 0;
        int temp = 0;
        if ( i < 0 ) {
            i = 0;
            j += (n-3);
        }
        
        while ((i + temp) < 7 && (j + temp) < 7) {
            //std::cout << "[" << (i+temp) << "][" << (j+temp) << "] ";
            if (board[i + temp][j + temp] == 'O') {
                Oc++;
                Xc = 0;
                if (Oc == 4) {
                    return 0;
                }
            } else if (board[i + temp][j + temp] == 'X') {
                Xc++;
                Oc = 0;
                if (Xc == 4) {
                    return 1;
                }
            } else {
                Oc = 0;
                Xc = 0;
            }
            temp++;
        }
        Oc = 0;
        Xc = 0;
    }

    // Check ascending diagonal win
    for (int n = 0; n < 7; n++) {
        //std::cout << "\n";
        int i = 3 + n;
        int j = 0;
        int temp = 0;
        if ( i > 6 ) {
            i = 6;
            j += (n-3);
        }
        while (i - temp >= 0 && j + temp < 7) {
            //std::cout << "[" << (i-temp) << "][" << (j+temp) << "] ";
            if (board[i - temp][j + temp] == 'O') {
                Oc++;
                Xc = 0;
                if (Oc == 4) {
                    return 0;
                }
            } else if (board[i - temp][j + temp] == 'X') {
                Xc++;
                Oc = 0;
                if (Xc == 4) {
                    return 1;
                }
            } else {
                Oc = 0;
                Xc = 0;
            }
            temp++;
        }
        Oc = 0;
        Xc = 0;
    }

    return -1;
}

int main() {

    // Initialize variables
    char board [7][7]; // [row] [column]
    int selected = 0;
    int winner = -1;
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

    while (winner == -1) {

        std::cout << "Choose column to drop chip (0-6): ";
        std::cin >> selected;

        // drop players chip
        dropChip(board, turn, selected);

        // drop CPU chip
        turn = swapTurn(turn);
        selected = rand()%7;

        // look for possible win
        for (int i = 0; i < 6; i++) {
            dropChip(board, turn, i);
            winner = winCheck(board);
            undoDrop(board, i);

            if (winner == 1) {
                selected = i;
                i = 7;
            }
        }
        dropChip(board, turn, selected);
        turn = swapTurn(turn);

        printBoard(board);

        winner = winCheck(board);
        if (winner == 0) {
            std::cout << "Player Wins!";
        } else if (winner == 1) {
            std::cout << "CPU Wins!";
        }

    }

    return 0;
}