

class Solver:
    __sudoku: list = []

    @staticmethod
    def __validate_matrix(matrix: list) -> bool:
        return (len(matrix) is 9 and (len(matrix[0])) is 9)

    @staticmethod
    def __is_valid_value(row: int, col: int, value: int) -> bool:
        for i in range(0, 9):
            if Solver.__sudoku[row][i] is value or Solver.__sudoku[i][col] is value:
                return False

        block_row: int = int(row / 3) * 3
        block_col: int = int(col / 3) * 3

        for i in range(block_row, (block_row + 3)):
            for k in range(block_col, (block_col + 3)):
                if Solver.__sudoku[i][k] is value:
                    return False

        return True

    @staticmethod
    def __solve_next_position(row: int, col: int) -> bool:
        if col >= 8:
            return Solver.__solve_position((row + 1), 0)
        else:
            return Solver.__solve_position(row, (col + 1))

    @staticmethod
    def __solve_position(row: int, col: int) -> bool:
        if row >= 9:
            return True

        if Solver.__sudoku[row][col]:
            return Solver.__solve_next_position(row, col)

        for value in range(1, 10):
            if Solver.__is_valid_value(row, col, value):
                Solver.__sudoku[row][col]: int = value

                if Solver.__solve_next_position(row, col):
                    return True

                Solver.__sudoku[row][col]: int = 0

        return False

    @staticmethod
    def display(matrix: list):
        for row in matrix:
            print(row)

    @staticmethod
    def solve(matrix: list) -> list:
        if Solver.__validate_matrix(matrix):
            Solver.__sudoku: list = matrix

            if (Solver.__solve_position(0, 0)):
                return Solver.__sudoku

        return None
