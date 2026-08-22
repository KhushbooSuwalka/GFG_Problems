//Given an array arr[] of integers, return the number of subarrays in arr[] which are strictly increasing with size greater or equal to 2. A subarray is a contiguous part of array. A subarray is strictly increasing if each element is greater then it's previous element if it exists.

// Examples:
// Input: arr[] = [1, 4, 5, 3, 7, 9]
// Output: 6
// Explanation: The strictly increasing subarrays are: [1, 4], [1, 4, 5], [4, 5], [3, 7], [3, 7, 9], [7, 9]

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        int n=arr.size();
        int count = 0;
        int len=0;
        
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                len++;
            }else{
                len = 0;
            }
            
            count += len;
        }
        
        return count;
    }
};
