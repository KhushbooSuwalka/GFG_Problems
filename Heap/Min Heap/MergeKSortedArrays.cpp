//Given a 2D matrix mat[][] of size n x m. Each row in the matrix is sorted in non-decreasing order, merge all the rows and return a single sorted array that contains all the elements of the matrix.

// Examples :
// Input: mat[][] = [[1, 3, 5, 7], [2, 4, 6, 8], [0, 9, 10, 11]]
// Output: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    vector<int> mergeArrays(vector<vector<int>> &mat) {  
        // Min Heap :- {value, {row, column}}
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;
        
        int n = mat.size();
        int m = mat[0].size();
        
        // Har row ka first element heap mein daalo
        for(int i = 0; i < n; i++) {
            pq.push({mat[i][0], {i, 0}});
        }
        
        vector<int> ans;
        
        // Jab tak heap empty nahi hota
        while(!pq.empty()) {
            // Smallest element nikalo
            auto temp = pq.top();
            pq.pop();
            
            int value = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;
            
            // Answer mein add karo
            ans.push_back(value);
            
            // Same row ka next element heap mein daalo
            if(col + 1 < m) {
                pq.push({mat[row][col + 1], {row, col + 1}});
            }
        }
        
        return ans;
    }
};