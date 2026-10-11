//Given an array arr[] containing both positive and negative integers, the task is to find the length of the longest subarray with a sum equals to 0.
// Note: A subarray is a contiguous part of an array, formed by selecting one or more consecutive elements while maintaining their original order.

// Examples:
// Input: arr[] = [15, -2, 2, -8, 1, 7, 10, 23]
// Output: 5
// Explanation: The longest subarray with sum equals to 0 is [-2, 2, -8, 1, 7].

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Idea: Prefix Sum + Hash Map
    // We keep:
    // - sum = prefix sum till current index
    // - mp[sum] = first index where this sum appeared
    // - If the same sum appears again at index i, then the elements between those two indices have sum 0.
    
    int maxLength(vector<int>& arr) {
        int sum=0;
        int ans=0;
        
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            
            if(sum==0){ //If sum itself is 0
                ans=i+1;
            }
            
            if(mp.find(sum) != mp.end()){
                ans=max(ans,i-mp[sum]);
            }else{
                mp[sum]=i; // Store only the first occurence
            }
        }
        
        return ans;
    }
};