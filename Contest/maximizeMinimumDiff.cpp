//Maximize the minimum difference between k elements
//Given an array arr[] of integers and an integer k, select k elements from the array such that the minimum absolute difference between any two of the selected elements is maximized. Return this maximum possible minimum difference.

// Examples:
// Input: arr[] = [2, 6, 2, 5], k = 3
// Output: 1
// Explanation: 3 elements out of 4 elements are to be selected with a minimum difference as large as possible. Selecting 2, 2, 5 will result in minimum difference as 0. Selecting 2, 5, 6 will result in minimum difference as 6 - 5 = 1

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& arr, int k, int mid) {
        int count = 1;
        int last = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - last >= mid) {
                count++;
                last = arr[i];
            }

            if (count >= k) {
                return true;
            }
        }

        return false;
    }

    int maxMinDiff(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());

        int low = 0;
        int high = arr.back() - arr.front();
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(arr, k, mid)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};