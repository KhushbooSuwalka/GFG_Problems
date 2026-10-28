//Given an array arr[] of positive integers, return the maximum bitwise AND value obtained by any pair (arr[i], arr[j]) such that i ≠ j.

// Examples:
// Input: arr[] = [4, 8, 12, 16]
// Output: 8
// Explanation: Pair (8,12) has the maximum AND value 8.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAND(vector<int>& arr) {
        int ans = 0;

        // Check bits from highest to lowest
        for (int bit = 20; bit >= 0; bit--) {
            int candidate = ans | (1 << bit);

            int count = 0;

            // Count numbers having all candidate bits
            for (int num : arr) {
                if ((num & candidate) == candidate) {
                    count++;
                }

                if (count >= 2)
                    break;
            }

            // If at least 2 numbers have these bits,we can keep this bit
            if (count >= 2) {
                ans = candidate;
            }
        }

        return ans;
    }
};