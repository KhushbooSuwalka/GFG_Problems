//Given two square matrices mat1[][] and mat2[][], each of size n × n. Multiply these two matrices and return the resulting matrix.

// Examples:
// Input: mat1[][] = [[1, 1, 1], [1, 1, 1], [1, 1, 1]], mat2[][] = [[1, 1, 1], [1, 1, 1], [1, 1, 1]]
// Output: [[3, 3, 3], [3, 3, 3], [3, 3, 3]]
// Explanation: After multiplying mat1 and mat2 we get the resulting matrix equal to [[3, 3, 3], [3, 3, 3], [3, 3, 3]].

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int n = mat1.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    ans[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }

        return ans;
    }
};