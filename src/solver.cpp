#include <cstdio>

#include "solver.hpp"

/**
 * Public
 */

bool Solver::solveSudoku(int matrix[9][9]) {
    return Solver::solvePosition(matrix, 0, 0);
}

void Solver::displaySudoku(int matrix[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int k = 0; k < 9; k++) {
            printf("%d ", matrix[i][k]);
        }

        printf("\n");
    }
}

/**
 * Private
 */

bool Solver::isValidValue(int matrix[9][9], int row, int col, int value) {
    /* Check vertically and horizontally */
    for (int i = 0; i < 9; i++) {
        if (matrix[i][col] == value || matrix[row][i] == value) {
            return false;
        }
    }

    for (int i = row; i < (row + 3); i++) {
        for (int k = col; k < (col + 3); k++) {
            if (matrix[i][k] == value) {
                return false;
            }
        }
    }

    return true;
}

bool Solver::solveNextPosition(int matrix[9][9], int row, int col) {
    if (col >= 8) {
        return Solver::solvePosition(matrix, (row + 1), 0);
    } else {
        return Solver::solvePosition(matrix, row, (col + 1));
    }
}

bool Solver::solvePosition(int matrix[9][9], int row, int col) {
    /* Sudoku is solved if trying to access row that is out of range */
    if (row >= 9) {
        return true;
    }

    /* If field is not empty, solve the next one */
    if (matrix[row][col]) {
        return Solver::solveNextPosition(matrix, row, col);
    }

    /* Try every value for each field and see if it leads to a solution */
    for (int value = 1; value < 10; value++) {
        if (Solver::isValidValue(matrix, row, col, value)) {
            matrix[row][col] = value;

            if (Solver::solveNextPosition(matrix, row, col)) {
                return true;
            }

            matrix[row][col] = 0;
        }
    }

    return false;
}
