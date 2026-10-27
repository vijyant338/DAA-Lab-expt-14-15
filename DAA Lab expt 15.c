//Name : Vijyant
//  Roll no : 25/DA/063

#include <stdio.h>
#include <stdbool.h>

// Define N for the N-Queens problem size (e.g., 4x4 board)
#define N 4

// A utility function to print the final chessboard solution
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j])
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
    printf("\n");
}

// A utility function to check if a queen can safely be placed at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // 1. Check this row on the left side (no other queen can be in the same row)
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // 2. Check upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // 3. Check lower diagonal on the left side
    for (i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// A recursive utility function to solve the N-Queen problem column by column
bool solveNQUtil(int board[N][N], int col) {
    // Base case: If all queens are placed successfully, return true
    if (col >= N)
        return true;

    // Consider the current column and try placing a queen in all rows one by one
    for (int i = 0; i < N; i++) {
        // Check if it's safe to place a queen at board[i][col]
        if (isSafe(board, i, col)) {
            // Place the queen
            board[i][col] = 1;

            // Recursively place the rest of the queens in subsequent columns
            if (solveNQUtil(board, col + 1))
                return true;

            // If placing the queen in board[i][col] leads to an invalid state,
            // BACKTRACK: remove the queen from board[i][col] and try the next row
            board[i][col] = 0; 
        }
    }

    // If the queen cannot be placed in any row of this column, return false to trigger backtracking
    return false;
}

// Main driver function to initialize the board and start the backtracking search
bool solveNQueens() {
    int board[N][N] = {0};

    if (solveNQUtil(board, 0) == false) {
        printf("Solution does not exist for %d-Queens.\n", N);
        return false;
    }

    printSolution(board);
    return true;
}

int main() {
    printf("Solution for the %d-Queens Problem:\n\n", N);
    solveNQueens();

    return 0;
}