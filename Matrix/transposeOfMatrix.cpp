//Given a square matrix of size n x n, return the transpose matrix of the given matrix.
// The transpose of a matrix is obtained by converting all the rows to columns and all the columns to rows.

// Examples:
// Input : mat[][] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
// Output : [[1, 4, 7], [2, 5, 8], [3, 6, 9]]
// Explanation: The first row [1, 2, 3] becomes the first column, the second row [4, 5, 6] becomes the second column, and the third row [7, 8, 9] becomes the third column.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        int n = mat.size();  
        // Traverse the upper triangle of the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Swap elements across the diagonal
                swap(mat[i][j], mat[j][i]);
            }
        }
        return mat;  
    }
};