//Given a 2D integer matrix mat[][], where every row and column is sorted in increasing order and a number x, return true if the element x is present in the matrix. Otherwise, return false.

// Examples:
// Input: mat[][] = [[3, 30, 38], [20, 52, 54], [35, 60, 69]], x = 62
// Output: false
// Explanation: 62 is not present in the matrix, so output is false.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool binarySearch(vector<int> arr,int n,int x){
        if(x<arr[0] || x>arr[n-1]) return false;
        
        int left=0,right=n-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(arr[mid]==x){
                return true;
            }else if(arr[mid]>x){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        
        return false;
    }
    
    bool matSearch(vector<vector<int>> &arr, int x) {
        int n=arr.size();
        int m=arr[0].size();
        
        for(int i=0;i<n;i++){
            if(binarySearch(arr[i],m,x)){
                return true;
            }
        }
        
        return false;
    }
};