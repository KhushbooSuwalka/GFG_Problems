//Kadane's Algorithm for maximum subarray
//You are given an integer array arr[]. You need to find the maximum sum of a subarray (containing at least one element) in the array arr[].

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int maxSum=INT_MIN;
        int currentSum=0;
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            currentSum += arr[i];
            maxSum = max(maxSum,currentSum);
            if(currentSum<0){
                currentSum = 0;
            }
        }
        
        return maxSum ;
        
    }
};
