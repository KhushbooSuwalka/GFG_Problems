//You are given an array arr[] where each element represents the length of a wooden plank. Your task is to construct the longest possible fence using these planks. The fence can be made by placing two plank at a distance of 1 unit. You are allowed to combine at most 2 planks to form one plank. However, joining three or more planks is not allowed, as it would compromise the fence's integrity. Furthermore, the lengths of all the planks used (whether single or combined) must be equal.
// Your goal is to return the length of the longest possible fence that can be built.

//Examples:
// Input: arr[] = [1, 3, 2, 5, 2, 5, 4, 2, 1]
// Output: 3
// Explanation: The longest possible fence can be made by using the following planks which gives a total length of 3 units:
// [(5) (1+4) (5) (2+3)].

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestFence(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        int ans=0;
        for(auto it:mp){
            ans=max(ans,it.second/2);
        }
        return ans;
    } 
};