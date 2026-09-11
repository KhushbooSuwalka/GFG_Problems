//The N-Queens puzzle is the problem of placing N queens on an N * N chessboard such that no two queens attack each other. Two queens attack each other if they are placed in the same row, the same column, or the same diagonal.
// Given an integer n representing the number of queens, find all distinct solutions to this puzzle. Each solution should be represented as an array of size n, where the ith element (1-based indexing) denotes the column position of the queen placed in the ith row.
// Note: You may return the solutions in any order.

// Examples:
// Input: n = 4
// Output: [[2, 4, 1, 3], [3, 1, 4, 2]]
// Explanation: There are 2 possible solutions for n = 4.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    bool isSafe(vector<int>& board, int row, int col) {

        // Check previous rows
        for(int i = 0; i < row; i++) {

            // Same column
            if(board[i] == col)
                return false;

            // Same diagonal
            if(abs(board[i] - col) == abs(i - row))
                return false;
        }

        return true;
    }

    void solve(int row, int n, vector<int>& board, vector<vector<int>>& ans) {

        // All queens are placed
        if(row == n) {
            vector<int> temp;

            for(int x : board)
                temp.push_back(x + 1);

            ans.push_back(temp);
            return;
        }

        // Try every column
        for(int col = 0; col < n; col++) {
            
            if(isSafe(board, row, col)) {
                
                // Place queen
                board.push_back(col);

                // Move to next row
                solve(row + 1, n, board, ans);

                // Remove queen = backtracking
                board.pop_back();
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<int> board;

        solve(0, n, board, ans);
        return ans;
    }
};

// Recursion tree will look like this for n = 4 :-
// Row 1
// │
// ├── Col 1
// │   ├── Row 2
// │   ├── Row 3
// │   └── ❌ stuck
// │       └── BACKTRACK
// │
// ├── Col 2
// │   ├── Row 2 → Col 4
// │   ├── Row 3 → Col 1
// │   └── Row 4 → Col 3
// │                    ↓
// │                ✅ [2,4,1,3]
// │
// ├── Col 3
// │   └── ...
// │
// └── Col 4
//     └── ...