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

// Approach 2:-

int longestFence(vector<int>& arr) {

    int n = arr.size();
    int ans = 0;

    // Try every possible target length
    for (int i = 0; i < n; i++) {

        // Case 1: target is an existing plank
        int target = arr[i];
        unordered_map<int, int> freq;

        for (int x : arr) {
            freq[x]++;
        }

        int count = freq[target];

        // Try making target using 2 planks
        for (const auto &x : freq) {

            int a = x.first;
            int b = target - a;

            if (a >= b)
                continue; // This prevents counting the same pair twice.

            if (freq.find(b) != freq.end()) {
                count += min(freq[a], freq[b]);
            }
        }

        if (count >= 2) {
            ans = max(ans, count - 1);
        }
    }

    // Also consider sums of two planks as target
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            int target = arr[i] + arr[j];
            unordered_map<int, int> freq;

            for (int x : arr) {
                freq[x]++;
            }

            int count = freq[target];

            for (auto p : freq) {
                int a = p.first;
                int b = target - a;

                if (a > b)
                    continue;

                if (freq.find(b) != freq.end()) {
                    if (a == b)
                        count += freq[a] / 2;
                    else
                        count += min(freq[a], freq[b]);
                }
                
            }

            if (count >= 2) {
                ans = max(ans, count - 1);
            }
        }
    }

    return ans;
}