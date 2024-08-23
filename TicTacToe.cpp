/*This Tic-Tac-Toe game lets the user play against a computer that makes random moves.
 The user (Player X) and the computer (Player O) take turns until one wins or the game ties.
 The game resets after a win or tie, and the user is prompted to play again or exit.*/



#include <iostream>

using namespace std;

void displayBoard(const char board[3][3]) {
    cout << "\nCurrent board:\n";
    for (int i = 0; i < 3; ++i) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
        if (i < 2) cout << "---|---|---" << endl;
    }
    cout << endl;
}

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char currentPlayer = 'X';
    bool gameFinished = false;
    int move;

    cout << "Welcome to Tic-Tac-Toe!\nPlayer X starts. Ready to play?\n";

    while (true) {
        displayBoard(board);

        cout << "Player " << currentPlayer << ", choose a spot (1-9): ";
        cin >> move;
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (move < 1 || move > 9 || board[row][col] != ' ') {
            cout << "Try again!" << endl;
            continue;
        }

        board[row][col] = currentPlayer;

        bool hasWinner = false;

        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
                hasWinner = true;
                break;
            }
        }

        for (int i = 0; i < 3; ++i) {
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
                hasWinner = true;
                break;
            }
        }

        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
            hasWinner = true;
        }

        if (hasWinner) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!!" << endl;
            gameFinished = true;
        } else {
            bool isTie = true;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (board[i][j] == ' ') {
                        isTie = false;
                        break;
                    }
                }
                if (!isTie) break;
            }
            if (isTie) {
                displayBoard(board);
                cout << "tie! " << endl;
                gameFinished = true;
            }
        }

        if (gameFinished) {
            cout << "Want to play again? (yes/no): ";
            char playAgain;
            cin >> playAgain;
            if (playAgain == 'yes' || playAgain == 'YES') {
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        board[i][j] = ' ';
                    }
                }
                currentPlayer = 'X';
                gameFinished = false;
                cout << "New game" << endl;
            } else {
                cout << "Thanks for playing!R" << endl;
                break;
            }
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}
