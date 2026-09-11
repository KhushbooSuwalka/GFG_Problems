//Given a 9*9 matrix mat[][] representing an incomplete Sudoku puzzle. Each cell contains a digit from 0 to 9, where 0 represents an empty cell and non-zero digits represent fixed values.
// Fill the empty cells to complete the puzzle. It is guaranteed that the puzzle has exactly one valid solution.
// A valid Sudoku solution must satisfy the following conditions:
// 1. Each digit from 1 to 9 appears exactly once in every row.
// 2. Each digit from 1 to 9 appears exactly once in every column.
// 3. Each digit from 1 to 9 appears exactly once in each of the nine 3*3 subgrids.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    // Check whether num can be placed at mat[row][col]
    bool isSafe(vector<vector<int>>& mat, int row, int col, int num) {

        // 1. Check row
        for(int j = 0; j < 9; j++) {
            if(mat[row][j] == num)
                return false;
        }

        // 2. Check column
        for(int i = 0; i < 9; i++) {
            if(mat[i][col] == num)
                return false;
        }

        // 3. Check 3 x 3 box
        int startRow = row - row % 3;
        int startCol = col - col % 3;

        for(int i = startRow; i < startRow + 3; i++) {
            for(int j = startCol; j < startCol + 3; j++) {
                if(mat[i][j] == num)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<int>>& mat) {

        // Find an empty cell
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {

                if(mat[i][j] == 0) {

                    // Try numbers 1 to 9
                    for(int num = 1; num <= 9; num++) {

                        if(isSafe(mat, i, j, num)) {

                            // Place number
                            mat[i][j] = num;

                            // Solve remaining Sudoku
                            if(solve(mat))
                                return true;

                            // Wrong choice -> undo
                            mat[i][j] = 0;
                        }
                    }

                    // No number worked
                    return false;
                }
            }
        }

        // No empty cell left
        return true;
    }

    void solveSudoku(vector<vector<int>>& mat) {
        solve(mat);
    }
};