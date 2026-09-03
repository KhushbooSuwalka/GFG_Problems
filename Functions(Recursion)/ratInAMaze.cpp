// Given a binary matrix maze[][] of size n × n containing values 0 and 1, find all possible paths for a rat to travel from the source cell (0, 0) to the destination cell (n - 1, n - 1). The rat can move in four directions: up(U), down(D), left(L), and right(R).
// 1. 1 represents an open cell through which the rat can move.
// 2. 0 represents a blocked cell that cannot be traversed.
// The rat can move only through open cells and cannot visit the same cell more than once in a path. Return all valid paths as strings consisting of 'U', 'D', 'L', and 'R', representing the sequence of moves taken by the rat.

// Note: Return the paths in lexicographically increasing order. If no valid path exists, return an empty list.

// Examples:
// Input: maze[][] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}}
// Output: ["DDRDRR", "DRDDRR"]
// Explanation: There are two valid paths from the source cell (0, 0) to the destination cell (3, 3).

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void solve(vector<vector<int>>& maze ,int row ,int col ,
               vector<vector<int>>& vis , string &path ,vector<string>& ans){
        
        int n = maze.size();
        
        //Reached destination
        if (row == n - 1 && col == n - 1) {
            ans.push_back(path);
            return;
        }
        
        //D,L,R,U
        int dr[] = {1, 0, 0, -1};        // Positive 1(1) indicates row will move to its next row ,and negative 1(-1) indicates row will move to  its previous row
        int dc[] = {0, -1, 1, 0};
        char dir[] = {'D', 'L', 'R', 'U'};
        
        for (int i = 0; i < 4; i++){     // Because these are 4 possible direction
            
            int nr = row + dr[i];          //nr means new row.
            int nc = col + dc[i];          //nc means new column.
            
            // Check valid move
            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < n &&
                maze[nr][nc] == 1 &&
                !vis[nr][nc]){
                
                //Choose
                vis[nr][nc] = 1;
                path.push_back(dir[i]);
                
                //Explore
                solve(maze, nr, nc, vis, path, ans);
                
                //Undo
                path.pop_back();
                vis[nr][nc] = 0;
            }
            
        }
        
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        int n = maze.size();
        
        if(maze[0][0]==0){     // Source cell is block cell
            return ans;
        }
        
        vector<vector<int>> vis(n,vector<int> (n,0));
        string path = "";
        
        vis[0][0] = 1;
        
        solve(maze, 0, 0, vis, path, ans);
        
        return ans;
    }
};