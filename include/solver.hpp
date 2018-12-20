#ifndef __SOLVER_HPP__
#define __SOLVER_HPP__

#include <vector>
#include <cstdint>

typedef std::vector<std::vector<uint8_t>> uint8Matrix;

class Solver {
public:
    static bool solveSudoku(uint8Matrix &matrix);
    static void displaySudoku(uint8Matrix matrix);

private:
    static bool isValidValue(uint8Matrix matrix, uint8_t row, uint8_t col, uint8_t value);
    static bool solveNextPosition(uint8Matrix &matrix, uint8_t row, uint8_t col);
    static bool solvePosition(uint8Matrix &matrix, uint8_t row, uint8_t col);
};

#endif /* __SOLVER_HPP__ */
