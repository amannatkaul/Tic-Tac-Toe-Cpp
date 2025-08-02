#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer = 'X';

void initializeBoard() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {
    cout << "\n";
    for(int i = 0; i < 3; i++) {
        cout << " ";
        for(int j = 0; j < 3; j++) {
            cout << board[i][j];
            if(j < 2) {
                cout << " | ";
            }
        }
        if(i < 2) {
            cout << "\n-----------\n";
        }
    }
    cout << "\n";
}

bool isValidMove(int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

bool checkWin() {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true;
        }
        if(board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
            return true;
        }
    }
    if(board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true;
    }
    if(board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true;
    }

    return false;
}

bool isDraw() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playGame() {
    int row, col;
    while(true) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter row and column (0 to 2): ";
        cin >> row >> col;

        if(isValidMove(row, col)) {
            board[row][col] = currentPlayer;

            if(checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            } else if(isDraw()) {
                displayBoard();
                cout << "It's a draw!\n";
                break;
            }

            switchPlayer();
        } else {
            cout << "Invalid move! Try again.\n";
        }
    }
}

int main() {
    initializeBoard();
    playGame();
    return 0;
}
