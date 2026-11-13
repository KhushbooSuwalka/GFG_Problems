//Given a 2D square matrix mat[][], rotate it by 180 degrees without using extra space.
// Note: You must rotate the matrix in place and modify the input matrix directly.

// Examples:
// Input:  mat[][] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
// Output: [[9, 8, 7], [6, 5, 4], [3, 2, 1]]
// Explanation: The output matrix is the input matrix rotated by 180 degrees.

#include<bits/stdc++.h>
using namespace std;

// Approach 1 :-

void rotateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
  
    // Create an auxiliary matrix
    vector<vector<int>> res(n, vector<int>(n));
  
    // move mat[i][j] to mat[n-i-1][n-j-1]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = mat[n - i - 1][n - j - 1];
        }
    }
    mat = res;
}

// Approach 2 :-

class Solution {
public:
    void rotateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();

        // Reverse the order of rows
        reverse(mat.begin(), mat.end());

        // Reverse every row
        for(int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }
};