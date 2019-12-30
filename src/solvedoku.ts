export type SudokuBoard = number[][];

export class Solvedoku {
  public static solve(board: SudokuBoard): SudokuBoard {
    if (!this.validateBoard(board)) {
      throw new Error('The sudoku board must be of type number[][]');
    }

    if (!this.solvePosition(board, 0, 0)) {
      throw new Error('The sudoku is unsolvable');
    }

    return board;
  }

  private static isValidValue(
    board: SudokuBoard,
    row: number,
    col: number,
    value: number
  ): boolean {
    /* Check vertically and horizontally */
    for (let i: number = 0; i < 9; i++) {
      if (board[row][i] === value || board[i][col] === value) {
        return false;
      }
    }

    /* Check in block */
    const blockRow: number = Math.floor(row / 3) * 3;
    const blockCol: number = Math.floor(col / 3) * 3;

    for (let row: number = blockRow; row < (blockRow + 3); row++) {
      for (let col: number = blockCol; col < (blockCol + 3); col++) {
        if (board[row][col] === value) {
          return false;
        }
      }
    }

    return true;
  }

  private static solveNextPosition(
    board: SudokuBoard,
    row: number,
    col: number
  ): boolean {
    if (col >= 8) {
      return this.solvePosition(board, ++row, 0);
    } else {
      return this.solvePosition(board, row, ++col);
    }
  }

  private static solvePosition(
    board: SudokuBoard,
    row: number,
    col: number
  ): boolean {
    if (row >= 9) {
      return true;
    }

    if (board[row][col]) {
      return this.solveNextPosition(board, row, col);
    }

    for (let value: number = 1; value < 10; value++) {
      if (this.isValidValue(board, row, col, value)) {
        board[row][col] = value;

        if (this.solveNextPosition(board, row, col)) {
          return true;
        }

        board[row][col] = 0;
      }
    }

    return false;
  }

  private static validateBoard(board: SudokuBoard): boolean {
    return (
      board.length === 9 &&
      board.every((row: any) => Array.isArray(row))
    );
  }
}
