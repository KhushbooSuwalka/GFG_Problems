//Given an array arr[], return the maximum possible length of a subarray such that its elements are arranged alternately either as even and odd or odd and even.

// Examples:
// Input: arr[] = [10, 12, 14, 7, 8]
// Output: 3
// Explanation: The max length of subarray is 3 and the subarray is [14, 7, 8]. Here the array starts as an even element and has odd and even elements alternately.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxEvenOdd(vector<int>& arr) {
        int n = arr.size();
        int curr = 1;
        int ans = 1;
        
        for(int i=1;i<n;i++){
            if(arr[i]%2 != arr[i-1]%2){
                curr++;
            }else{
                curr=1;
            }
            ans = max(ans,curr);
        }
        
        return ans;
    }
};