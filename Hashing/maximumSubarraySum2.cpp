//Maximum Sum Subarray 2
//Given an array arr[] of integers and two integers a and b, find the maximum possible sum of a contiguous subarray whose length is at least a and at most b.
// The subarray must be contiguous and its length must lie within the range [a, b] inclusive.

// Examples:
// Input: arr[] = [4, 5, -1, -2, 6], a = 2, b = 4
// Output: 9
// Explanation: The subarray [4, 5] has length 2 and sum 9, which is the maximum among all subarrays of length between 2 and 4.

#include <bits/stdc++.h>
using namespace std;

// Using sliding window and prefix map

int maxSubarrSum(vector<int> &arr, int a, int b) {
    int n = arr.size();

    // compute prefix sum of the array
    for (int i = 1; i < n; i++) {
        arr[i] += arr[i - 1];
    }

    // to store the maximum sum found
    int maxi = arr[a-1];

    // map to track prefix sum frequencies
    map<int, int> mp;
    mp[0]++;

    for (int i = a; i < n; i++) {
        // remove prefix[i - b - 1] from map if it's outside  the valid window
        if (i > b) {
            int oldVal = arr[i - b - 1];
            mp[oldVal]--;
            if (mp[oldVal] == 0)
                mp.erase(oldVal);
        }
        else if(i == b){
            mp[0]--;
            if(mp[0] == 0){
                mp.erase(0);
            }
        }

        // insert prefix[i - a] into map
        int newVal = arr[i - a];
        mp[newVal]++;

        // subtract minimum prefix from current to get valid sum
        maxi = max(maxi, arr[i] - mp.begin()->first);
    }

    return maxi;
}