//Given a matrix mat[][] of size n × n, where mat[i][j] represents the maximum number of steps a rat can jump either forward (right) or downward from that cell, find a path for the rat to reach from the top-left cell (0, 0) to the bottom-right cell (n - 1, n - 1). A cell containing 0 is blocked and cannot be used in the path. It is guaranteed that the cell mat[n-1][n-1] is not 0.
// Return an n × n matrix where 1 represents the cells included in the path and 0 represents the remaining cells. If no valid path exists, return [[-1]].
// Note: If multiple valid paths exist, choose the path with the shortest possible jumps first. For the same jump length, moving forward (right) should be preferred over moving downward.

// Example:
// Input: mat[][] = [[2, 1, 0, 0], [3, 0, 0, 1], [0, 1, 0, 1], [0, 0, 0, 1]]
// Output: [[1, 0, 0, 0], [1, 0, 0, 1], [0, 0, 0, 1], [0, 0, 0, 1]]

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Backtracking and Recursion

class Solution {
  public:
    bool solve(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& path) {
        int n = mat.size();

        // Destination reached
        if(i == n-1 && j == n-1) {
            path[i][j] = 1;
            return true;
        }

        // Current cell is blocked
        if(mat[i][j] == 0) {
            return false;
        }

        // Mark current cell as part of path
        path[i][j] = 1;

        int jump = mat[i][j];

        // Try jumps from 1 to jump ...... First RIGHT, then DOWN
        for(int step = 1; step <= jump; step++) {

            // Move RIGHT
            if(j + step < n) {
                if(solve(mat, i, j + step, path))
                    return true;
            }

            // Move DOWN
            if(i + step < n) {
                if(solve(mat, i + step, j, path))
                    return true;
            }
        }

        // This cell doesn't lead to destination
        path[i][j] = 0;

        return false;
    }

    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {
        int n = mat.size();

        vector<vector<int>> path(n, vector<int>(n, 0));

        if(solve(mat, 0, 0, path))
            return path;

        return {{-1}};
    }
};

// OR 

class Solution {
  public:

    bool solve(vector<vector<int>>& mat, int i, int j,
               vector<vector<int>>& path,
               vector<vector<int>>& dp) {

        int n = mat.size();

        // Destination
        if(i == n-1 && j == n-1) {
            path[i][j] = 1;
            return true;
        }

        // Blocked cell
        if(mat[i][j] == 0)
            return false;

        // Already calculated
        if(dp[i][j] != -1)
            return dp[i][j];

        path[i][j] = 1;

        int jump = mat[i][j];

        // Try shorter jumps first
        for(int step = 1; step <= jump; step++) {

            // RIGHT first
            if(j + step < n) {
                if(solve(mat, i, j + step, path, dp)) {
                    dp[i][j] = 1;
                    return true;
                }
            }

            // DOWN second
            if(i + step < n) {
                if(solve(mat, i + step, j, path, dp)) {
                    dp[i][j] = 1;
                    return true;
                }
            }
        }

        // No path from this cell
        path[i][j] = 0;
        dp[i][j] = 0;

        return false;
    }

    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {
        int n = mat.size();

        vector<vector<int>> path(n, vector<int>(n, 0));
        vector<vector<int>> dp(n, vector<int>(n, -1));

        if(solve(mat, 0, 0, path, dp))
            return path;

        return {{-1}};
    }
};