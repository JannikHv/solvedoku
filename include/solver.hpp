#ifndef __SOLVER_HPP__
#define __SOLVER_HPP__

class Solver {
public:
    static bool solveSudoku(int matrix[9][9]);
    static void displaySudoku(int matrix[9][9]);

private:
    static bool isValidValue(int matrix[9][9], int row, int col, int value);
    static bool solveNextPosition(int matrix[9][9], int row, int col);
    static bool solvePosition(int matrix[9][9], int row, int col);
};

#endif /* __SOLVER_HPP__ */
