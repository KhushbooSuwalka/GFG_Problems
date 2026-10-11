//Given an array arr[] containing 0s and 1s. Count the number of subarrays having equal number of 0s and 1s.

// Examples:
// Input: arr[] = [1, 0, 0, 1, 0, 1, 1]
// Output: 8
// Explanation: The index range for the 8 sub-arrays are: (0, 1), (2, 3), (0, 3), (3, 4), (4, 5) ,(2, 5), (0, 5), (1, 6)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& arr) {
        unordered_map<int, int> mp;
        int sum = 0;
        int ans = 0;

        // sum 0 has appeared once before array starts
        mp[0] = 1;

        for (int i = 0; i < arr.size(); i++) {
            // 0 -> -1
            // 1 -> +1
            if (arr[i] == 0)
                sum--;
            else
                sum++;

            // Same sum already appeared
            if (mp.find(sum) != mp.end()) {
                ans += mp[sum];
            }

            // Current sum ki frequency badha do
            mp[sum]++;
        }

        return ans;
    }
};