#include <iostream>
using namespace std;

#define N 9

void printBoard(int grid[N][N]) {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cout << grid[r][c] << " ";
        }
        cout << endl;
    }
}

bool isValid(int grid[N][N], int row, int col, int num) {
   
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num) return false;
    }

    for (int x = 0; x < N; x++) {
        if (grid[x][col] == num) return false;
    }
  
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (grid[startRow + r][startCol + c] == num) return false;
        }
    }
    return true;
}

bool solveSudoku(int grid[N][N]) {
    int row = -1, col = -1;
    bool emptyFound = false;
    
  
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (grid[r][c] == 0) {
                row = r;
                col = c;
                emptyFound = true;
                break;
            }
        }
        if (emptyFound) break;
    }
    
    if (!emptyFound) return true;

    for (int num = 1; num <= 9; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num; 
            if (solveSudoku(grid)) return true; 
            grid[row][col] = 0; 
        }
    }
    return false; 
}

int main() {
    int grid[N][N] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    cout << "Initial Sudoku:\n";
    printBoard(grid);

    if (solveSudoku(grid)) {
        cout << "\nSolved Sudoku:\n";
        printBoard(grid);
    } else {
        cout << "\nNo solution exists.\n";
    }

    return 0;
}
