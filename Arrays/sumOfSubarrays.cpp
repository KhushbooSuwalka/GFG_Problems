//Given an array arr[], find the sum of all the subarrays of the given array.
// Note: It is guaranteed that the total sum will fit within a 32-bit integer range.

#include<bits/stdc++.h>
using namespace std;

//Approach 1 :- Element Contribution Method

class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        int n=arr.size();
        int result=0;
        
        for(int i=0;i<n;i++){
            result += arr[i]*(i+1)*(n-i);
        }
        
        return result;
    }
};