#include <iostream>
using namespace std;

const int N = 2; // Size of the Sudoku grid (2x2)
int grid[N][N];

// Function to print the Sudoku grid
void printGrid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if it's safe to place the number in the given row and column
bool canPlace(int row, int col, int num) {
    // Check if the number is not present in the same row and column
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false; // If number already exists in row or column, return false
        }
    }
    return true;
}

// Backtracking function to solve the Sudoku puzzle
bool solveSudoku(int row, int col) {
    // If we've reached the last column, move to the next row
    if (row == N - 1 && col == N) {
        printGrid(); // Print the solution when all cells are filled
        return true; // All cells are filled
    }

    // If column is completed, move to the next row
    if (col == N) {
        row++;
        col = 0;
    }

    // If the current cell is already filled, move to the next cell
    if (grid[row][col] != 0) {
        return solveSudoku(row, col + 1);
    }

    // Try placing numbers from 1 to N
    for (int num = 1; num <= N; num++) {
        if (canPlace(row, col, num)) {
            grid[row][col] = num; // Place the number

            // Recursively try to solve the rest of the grid
            if (solveSudoku(row, col + 1)) {
                return true;
            }

            // If placing num didn't work, backtrack
            grid[row][col] = 0; // Reset the cell
        }
    }
    return false; // No solution found
}

int main() {
    cout << "Enter the initial Sudoku grid (0 for empty cells):\n";
    
    // Input the initial Sudoku grid
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    // Solve the Sudoku and print the solution
    cout << "Sudoku solution:\n";
    if (!solveSudoku(0, 0)) {
        cout << "No solution exists for the given Sudoku.\n";
    }

    return 0;
}

