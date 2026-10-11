//You are given an integer array arr[] and a value k. The task is to find the count of all sub-arrays whose sum is divisible by k.

// Examples:
// Input: arr[] = [4, 5, 0, -2, -3, 1], k = 5
// Output: 7
// Explanation: There are 7 sub-arrays whose sum is divisible by k: [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3] and [-2, -3]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subCount(vector<int>& arr, int k) {        
        unordered_map<int, int> mp;    
        mp[0] = 1;
        
        long long sum = 0;
        int count = 0;
        
        for(int s : arr) {
            sum += s; 
            int r = sum % k;
            
            if(r < 0) {
                r += k;
            }
            
            if(mp.find(r) != mp.end()) {
                count += mp[r];
            }
            
            mp[r]++;
        }
        
        return count;
    }
};