//Given a rectangular matrix mat[][] of size n x m, and return a 1D array containing all its elements in spiral order.

// Examples:
// Input: mat[][] = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]
// Output: [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spirallyTraverse(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = m - 1;
        vector<int> ans;

        while(top <= bottom && left <= right) {
            // 1. Left to Right
            for(int i = left; i <= right; i++) {
                ans.push_back(mat[top][i]);
            }
            top++;

            // 2. Top to Bottom
            for(int i = top; i <= bottom; i++) {
                ans.push_back(mat[i][right]);
            }
            right--;

            // 3. Right to Left
            if(top <= bottom) {
                for(int i = right; i >= left; i--) {
                    ans.push_back(mat[bottom][i]);
                }
                bottom--;
            }

            // 4. Bottom to Top
            if(left <= right) {
                for(int i = bottom; i >= top; i--) {
                    ans.push_back(mat[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};