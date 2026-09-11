//You are given a matrix mat[][] of size n*m containing english alphabets and a string word. Check if the word exists on the mat[][] or not.
// 1. The word can be constructed by using letters from adjacent cells, either horizontally or vertically.
// 2. The same cell cannot be used more than once.

// Examples :
// Input: mat[][] = [['T', 'E', 'E'], ['S', 'G', 'K'], ['T', 'E', 'L']], word = "GEEK"
// Output: true

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool solve(vector<vector<char>>& mat, string& word, int row, int col, int index) {

        int n = mat.size();
        int m = mat[0].size();

        // Word completely found
        if(index == word.size())
            return true;

        // Out of boundary
        if(row < 0 || row >= n || col < 0 || col >= m)
            return false;

        // Current character does not match
        if(mat[row][col] != word[index])
            return false;

        // Mark current cell as visited
        char temp = mat[row][col];
        mat[row][col] = '#';

        // Try all 4 directions
        bool found =
            solve(mat, word, row + 1, col, index + 1) ||  // Down
            solve(mat, word, row - 1, col, index + 1) ||  // Up
            solve(mat, word, row, col + 1, index + 1) ||  // Right
            solve(mat, word, row, col - 1, index + 1);    // Left

        // Backtrack: restore original character
        mat[row][col] = temp;

        return found;
    }


    bool isWordExist(vector<vector<char>>& mat, string &word) {

        int n = mat.size();
        int m = mat[0].size();

        // Try every cell as starting point
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(mat[i][j] == word[0]) {

                    if(solve(mat, word, i, j, 0))
                        return true;
                }
            }
        }

        return false;
    }
};