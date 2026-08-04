//Max Circular Subarray Sum
//You are given a circular array arr[] of integers, find the maximum possible sum of a non-empty subarray. In a circular array, the subarray can start at the end and wrap around to the beginning. Return the maximum non-empty subarray sum, considering both non-wrapping and wrapping cases.

#include<bits/stdc++.h>
using namespace std;

//Approach 1 :- Kadane's Algorithm

class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        int totalSum=0;
        int currMax = 0,currMin = 0;
        int maxSum = arr[0],minSum = arr[0];
        
        for(int i=0;i<arr.size();i++){
            currMax = max(currMax+arr[i],arr[i]);
            maxSum = max(maxSum,currMax);
            
            currMin = min(currMin+arr[i],arr[i]);
            minSum = min(minSum,currMin);
            
            totalSum = totalSum + arr[i];
            
        }
        
        int normalSum = maxSum;
        int circularSum = totalSum - minSum;
        
        if(minSum == totalSum){
            return normalSum;
        }
        
        return max(maxSum,circularSum);
        
    }
    
};