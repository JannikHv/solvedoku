#ifndef __SOLVER_HPP__
#define __SOLVER_HPP__

#include <vector>

typedef std::vector<std::vector<int>> IntMatrix;

class Solver {
public:
    static bool solveSudoku(IntMatrix &matrix);
    static void displaySudoku(IntMatrix matrix);

private:
    static bool isValidValue(IntMatrix matrix, int row, int col, int value);
    static bool solveNextPosition(IntMatrix &matrix, int row, int col);
    static bool solvePosition(IntMatrix &matrix, int row, int col);
};

#endif /* __SOLVER_HPP__ */
