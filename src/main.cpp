#include <cstdio>

#include "solver.hpp"

int main(void)
{
    int matrix[9][9] = {
        { 0, 0, 5, 3, 0, 0, 0, 0, 0 },
        { 8, 0, 0, 0, 0, 0, 0, 2, 0 },
        { 0, 7, 0, 0, 1, 0, 5, 0, 0 },
        { 4, 0, 0, 0, 0, 5, 3, 0, 0 },
        { 0, 1, 0, 0, 7, 0, 0, 0, 6 },
        { 0, 0, 3, 2, 0, 0, 0, 8, 0 },
        { 0, 6, 0, 5, 0, 0, 0, 0, 9 },
        { 0, 0, 4, 0, 0, 0, 0, 3, 0 },
        { 0, 0, 0, 0, 0, 9, 7, 0, 0 }
    };

    if (Solver::solveSudoku(matrix)) {
        printf("Sudoku solved:\n");
        Solver::displaySudoku(matrix);
        return 0;
    } else {
        printf("Given sudoku not solvable:\n");
        Solver::displaySudoku(matrix);
        return 1;
    }
}
