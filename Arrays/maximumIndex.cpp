//Given an array arr[] of positive integers, return the maximum difference between two indices j and i (i.e., j - i) such that arr[i] ≤ arr[j] and i ≤ j.

// Examples:
// Input: arr[] = [1, 10]
// Output: 1
// Explanation: arr[0] ≤ arr[1] so (j-i) is 1-0 = 1.

// Input: arr[] = [34, 8, 10, 3, 2, 80, 30, 33, 1]
// Output: 6
// Explanation: In the given array arr[1] < arr[7] satisfying the required condition(arr[i] ≤ arr[j]) thus giving the maximum difference of j - i which is 6(7-1).

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxIndexDiff(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> leftMin(n);
        vector<int> rightMax(n);
        
        leftMin[0] = arr[0];
        for(int i=1;i<n;i++){
            leftMin[i] = min(leftMin[i-1],arr[i]);
        }
        
        rightMax[n-1] = arr[n-1];
        for(int i = n-2;i>=0;i--){
            rightMax[i] = max(rightMax[i+1],arr[i]);
        }
        
        int i=0,j=0,maximum =0;
        
        while(i<n && j<n){
            if(leftMin[i] <= rightMax[j]){
                maximum = max(maximum,j-i);
                j++;
            }else{
                i++;  
            }
        }
         
        return maximum ;
    }
};