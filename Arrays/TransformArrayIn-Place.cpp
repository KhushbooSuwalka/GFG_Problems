//Given an integer array arr[] of size n, where each element lies in the range [0, n-1], transform the array such that every element at index i becomes: arr[i]=arr[arr[i]].
// The transformation must be performed in-place, meaning the same array should store both the original and updated values without using another array.

// Examples:
// Input: arr[] = [1, 0]
// Output: [0, 1]
// Explanation: The original array is [1, 0]. 
// At index 0, arr[0] = 1, so the new value becomes arr[1] = 0. 
// At index 1, arr[1] = 0, so the new value becomes arr[0] = 1. 
// Thus, the transformed array becomes [0, 1].

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void arrange(vector<int>& arr) {
        int n = arr.size();

        // Step 1: Store original and new values together
        for (int i = 0; i < n; i++) {
            int oldValue = arr[i] % n;
            int newValue = arr[oldValue] % n;

            arr[i] = arr[i] + newValue * n;
        }

        // Step 2: Extract the new values
        for (int i = 0; i < n; i++) {
            arr[i] = arr[i] / n;
        }
    }
};