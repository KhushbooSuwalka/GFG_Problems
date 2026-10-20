//Given a square matrix mat[][] of size n x n, return the minimum operations required to make the matrix beautiful. A beautiful matrix is defined as a square matrix in which the sum of elements in every row and every column is equal. 
// In one operation, you are allowed to increment the value of any single cell by 1.

// Examples:
// Input: mat[][] = [[1, 2], [3, 4]]
// Output: 4
// Explanation:
// -> Increment value of cell(0, 0) by 3, 
// -> Increment value of cell(0, 1) by 1. 
// -> Matrix after the operations: [[4, 3], [3, 4]]
// -> Here, sum of each row and column is 7.
// Hence total 4 operation are required.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<int> row(n,0);
        vector<int> col(n,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                row[i]+=mat[i][j];
                col[j]+=mat[i][j];
            }
        }
        
        int maxSum=0;
        for(int i=0;i<n;i++){
            maxSum=max(maxSum,row[i]);
            maxSum=max(maxSum,col[i]);
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=maxSum-row[i];
        }
        
        return ans;
    }
};