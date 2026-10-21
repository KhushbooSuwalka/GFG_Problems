//Given a row-wise sorted matrix mat[][], where the number of rows and columns is always odd. Return the median of the matrix.

// Examples:
// Input: mat[][] = [[1, 3, 5], [2, 6, 9], [3, 6, 9]]
// Output: 5
// Explanation: Sorting matrix elements gives us [1, 2, 3, 3, 5, 6, 6, 9, 9]. Hence, 5 is median.

#include <bits/stdc++.h>
using namespace std;

// Approach 1 :- Using Binary Search

class Solution {
  public:
    int countLessEqual(vector<int>& row,int x){
        int low=0 , high=row.size()-1;
        int ans=row.size();
        
        while(low<=high){
            int mid=(low+high)/2;
            if(row[mid]<=x){
                low=mid+1;
            }else{
                ans=mid;
                high=mid-1;
            }
        }
        
        return ans;
    }
    
    int median(vector<vector<int>> &mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        int low=mat[0][0];
        int high=mat[0][m-1];
        
        for(int i=1;i<n;i++){
            low=min(low,mat[i][0]);
            high=max(high,mat[i][m-1]);
        }
        
        int required=(n*m+1)/2;
        
        while(low<high){
            int mid = low + (high-low)/2;
            int count=0;
            
            for(int i=0;i<n;i++){
                count+=countLessEqual(mat[i],mid);
            }
            
            if(count<required){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        
        return low;
    }
};