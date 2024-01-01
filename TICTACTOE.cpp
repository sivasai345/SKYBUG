#include <iostream>
#include <vector>

// Function prototypes
void initializeBoard(std::vector<std::vector<char>> &board);
void displayBoard(const std::vector<std::vector<char>> &board);
bool makeMove(std::vector<std::vector<char>> &board, char currentPlayer);
bool checkWin(const std::vector<std::vector<char>> &board, char currentPlayer);
bool checkDraw(const std::vector<std::vector<char>> &board);
char switchPlayer(char currentPlayer);
bool playAgain();

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';

    do {
        initializeBoard(board);
        displayBoard(board);

        while (!checkWin(board, currentPlayer) && !checkDraw(board)) {
            if (makeMove(board, currentPlayer)) {
                displayBoard(board);
                currentPlayer = switchPlayer(currentPlayer);
            }
        }

        if (checkWin(board, currentPlayer)) {
            std::cout << "Player " << currentPlayer << " wins!\n";
        } else {
            std::cout << "It's a draw!\n";
        }

    } while (playAgain());

    std::cout << "Thanks for playing!\n";

    return 0;
}

void initializeBoard(std::vector<std::vector<char>> &board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const std::vector<std::vector<char>> &board) {
    std::cout << "-------------\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "| ";
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j] << " | ";
        }
        std::cout << "\n-------------\n";
    }
}

bool makeMove(std::vector<std::vector<char>> &board, char currentPlayer) {
    int row, col;
    std::cout << "Player " << currentPlayer << "'s turn. Enter your move (row and column): ";
    std::cin >> row >> col;

    // Check if the chosen cell is empty
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        return true;
    } else {
        std::cout << "Invalid move. Try again.\n";
        return false;
    }
}

bool checkWin(const std::vector<std::vector<char>> &board, char currentPlayer) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }

    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }

    return false;
}

bool checkDraw(const std::vector<std::vector<char>> &board) {
    // Check if the board is full (no empty spaces)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}

bool playAgain() {
    char choice;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
