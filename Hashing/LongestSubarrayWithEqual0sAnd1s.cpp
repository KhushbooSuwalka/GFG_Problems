//Given an array arr of 0s and 1s. Find and return the length of the longest subarray with equal number of 0s and 1s.

// Examples:
// Input: arr[] = [1, 0, 1, 1, 1, 0, 0]
// Output: 6
// Explanation: arr[1...6] is the longest subarray with three 0s and three 1s.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLen(vector<int>& arr) {
        unordered_map<int, int> mp;
        int sum = 0;
        int ans = 0;

        // sum 0 already exists before the array starts
        mp[0] = -1;

        for (int i = 0; i < arr.size(); i++) {
            // 0 ko -1 maan lo
            if (arr[i] == 0)
                sum += -1;
            else
                sum += 1;

            // Agar same sum pehle aa chuka hai
            if (mp.find(sum) != mp.end()) {
                ans = max(ans, i - mp[sum]);
            } else {
                // Pehli baar sum mila, index store karo
                mp[sum] = i;
            }
        }

        return ans;
    }
};