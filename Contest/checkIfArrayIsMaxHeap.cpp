// Given an array arr[], determine whether it represents the level-order traversal of a valid max heap. Return true if it does; otherwise, return false.

// Examples :
// Input: arr[] = [90, 15, 10, 7, 12, 2]
// Output: true
// Explanation: The given array represents the following tree. Each parent node is greater than or equal to its children, so the max-heap property holds.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMaxHeap(vector<int>& arr) {
        int n = arr.size();

        // Har parent node ko check karo
        for(int i = 0; i < n/2; i++) {
            
            // Left child
            int left = 2 * i + 1;
            
            if(arr[i] < arr[left])
                return false;

            // Right child
            int right = 2 * i + 2;
            
            if(right < n && arr[i] < arr[right])
                return false;
        }

        return true;
    }
};