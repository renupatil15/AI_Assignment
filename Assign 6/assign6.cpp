#include <iostream>
using namespace std;

#define N 8

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j]) return false;

    return true;
}

bool solveNQueens(int board[N][N], int row) {
    if (row >= N) {
        printBoard(board);  
        return true;
    }

    bool foundSolution = false;

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1; 
            foundSolution = solveNQueens(board, row + 1) || foundSolution;
            board[row][col] = 0; 
        }
    }
    return foundSolution;
}

int main() {
    int board[N][N] = {0};

    cout << "8-Queens Problem Solutions:\n\n";
    if (!solveNQueens(board, 0)) {
        cout << "No solution exists.\n";
    }
    return 0;
}
