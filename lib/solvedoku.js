const Solvedoku = (function() {
    let sudoku;

    /**
     * @param matrix Array<Array<int>>
     *
     * @return bool
     */
    function validateMatrix(matrix) {
        return (matrix.length === 9 && matrix[0].length === 9);
    }

    /**
     * @param row   int
     * @param col   int
     * @param value int
     *
     * @global sudoku Array<Array<int>>
     *
     * @return bool
     */
    function isValidValue(row, col, value) {
        for (let i = 0; i < 9; i++) {
            if (sudoku[row][i] === value || sudoku[i][col] === value) {
                return false;
            }
        }

        const block_row = Math.floor(row / 3) * 3;
        const block_col = Math.floor(col / 3) * 3;

        for (let i = block_row; i < (block_row + 3); i++) {
            for (let k = block_col; k < (block_col + 3); k++) {
                if (sudoku[i][k] === value) {
                    return false;
                }
            }
        }

        return true;
    }

    /**
     * @param row int
     * @param col int
     *
     * @global sudoku Array<Array<int>>
     *
     * @return bool
     */
    function solveNextPosition(row, col) {
        if (col >= 8) {
            return solvePosition((row + 1), 0);
        } else {
            return solvePosition(row, (col + 1));
        }
    }

    /**
     * @param row int
     * @param col int
     *
     * @global sudoku Array<Array<int>>
     *
     * @return bool
     */
    function solvePosition(row, col) {
        if (row >= 9) {
            return true;
        }

        if (sudoku[row][col]) {
            return solveNextPosition(row, col);
        }

        for (let value = 1; value < 10; value++) {
            if (isValidValue(row, col, value)) {
                sudoku[row][col] = value;

                if (solveNextPosition(row, col)) {
                    return true;
                }

                sudoku[row][col] = 0;
            }
        }

        return false;
    }

    /**
     * @param matrix Array<Array<int>>
     */
    this.display = function(matrix) {
        matrix.forEach(function(row) {
            console.log(row);
        });
    }

    /**
     * @param matrix Array<Array<int>>
     *
     * @return Array<Array<int>> || null
     */
    this.solve = function(matrix) {
        if (validateMatrix(matrix)) {
            sudoku = matrix;

            if (solvePosition(0, 0)) {
                return sudoku;
            }
        }

        return null;
    }

    return this;
})();
