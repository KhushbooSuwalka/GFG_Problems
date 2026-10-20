//Given a 2D matrix mat[][] of size n x m. Modify the matrix such that if mat[i][j] is 0, all the elements in the i-th row and j-th column are set to 0.

// Examples:
// Input: mat[][] = [[1, -1, 1], [-1, 0, 1], [1, -1, 1]]    
// Output: [[1, 0, 1], [0, 0, 0], [1, 0, 1]]   
// Explanation: mat[1][1] = 0, so all elements in row 1 and column 1 are updated to zeroes.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int> row(n,0);
        vector<int> col(m,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row[i]==1 || col[j]==1){
                    mat[i][j]=0;
                }
            }
        }
    }
};