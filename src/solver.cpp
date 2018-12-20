#include <cstdint>
#include <cstdio>

#include "solver.hpp"

/**
 * Public
 */

bool Solver::solveSudoku(uint8Matrix &matrix)
{
    return Solver::solvePosition(matrix, 0, 0);
}

void Solver::displaySudoku(uint8Matrix matrix)
{
    for (uint8_t i = 0; i < (uint8_t) matrix.size(); i++) {
        for (uint8_t k = 0; k < (uint8_t) matrix[i].size(); k++) {
            std::printf("%d ", matrix[i][k]);
        }

        std::printf("\n");
    }
}

/**
 * Private
 */

bool Solver::isValidValue(uint8Matrix matrix, uint8_t row, uint8_t col, uint8_t value)
{
    /* Check vertically and horizontally */
    for (uint8_t i = 0; i < (uint8_t) matrix.size(); i++) {
        if (matrix[i][col] == value || matrix[row][i] == value) {
            return false;
        }
    }

    /* Check block */
    const uint8_t block_row = (uint8_t) (row / 3) * 3;
    const uint8_t block_col = (uint8_t) (col / 3) * 3;

    for (uint8_t i = block_row; i < (block_row + 3); i++) {
        for (uint8_t k = block_col; k < (block_col + 3); k++) {
            if (matrix[i][k] == value) {
                return false;
            }
        }
    }

    return true;
}

bool Solver::solveNextPosition(uint8Matrix &matrix, uint8_t row, uint8_t col)
{
    if (col >= (matrix[row].size() - 1)) {
        return Solver::solvePosition(matrix, (row + 1), 0);
    } else {
        return Solver::solvePosition(matrix, row, (col + 1));
    }
}

bool Solver::solvePosition(uint8Matrix &matrix, uint8_t row, uint8_t col)
{
    /* Sudoku is solved if trying to access row that is out of range */
    if (row >= matrix.size()) {
        return true;
    }

    /* If field is not empty, solve the next one */
    if (matrix[row][col]) {
        return Solver::solveNextPosition(matrix, row, col);
    }

    /* Try every value for each field and see if it leads to a solution */
    for (uint8_t value = 1; value < 10; value++) {
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
