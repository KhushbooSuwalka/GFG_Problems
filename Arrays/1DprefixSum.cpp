// 1-D prefix sum
//Given an array arr[], the goal is to compute its prefix sum array. The prefix sum array, prefixSum[], should be of the same length as arr[], where each element prefixSum[i] represents the sum of all elements from the start of the array up to index i, i.e., prefixSum[i] = arr[0] + arr[1] + .... + arr[i].

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> prefSum(vector<int> &arr) {
        int n = arr.size();
        vector<int> prefixSum(n);
        
        prefixSum[0]=arr[0];
        
        for(int i=1;i<n;i++){
            prefixSum[i] = prefixSum[i-1] + arr[i];
        }
        
        return prefixSum;
    }
};

