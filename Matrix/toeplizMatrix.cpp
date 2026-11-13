//Given a matrix mat[][], determine whether it is a Toeplitz matrix or not.
// A Toeplitz matrix (also known as a diagonal-constant matrix) is a matrix in which every descending diagonal from left to right contains the same element.

// Examples:
// Input: mat[][] = [[6, 7, 8], [4, 6, 7], [1, 4, 6]]
// Output: true
// Explanation: The matrix is Toeplitz because every diagonal from top-left to bottom-right has the same elements. 
// For example, the main diagonal is 6 → 6 → 6, and other diagonals like 7 -> 7 and 4 -> 4 are also constant. 

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(mat[i][j] != mat[i - 1][j - 1])
                    return false;
            }
        }
        return true;
    }
};