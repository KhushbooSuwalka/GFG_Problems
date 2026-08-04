//Maximum sum subarray removing at most one
//Given an array arr[], find the maximum sum of a non-empty subarray. You are allowed to skip at most one element in the subarray.
// Note: After skipping the element, the subarray must still be non-empty.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumSubarray(vector<int>& arr) {
        int n = arr.size();
        vector<int> forward(n), backward(n);

        // Forward Kadane
        forward[0] = arr[0];
        int ans = arr[0];

        for (int i = 1; i < n; i++) {
            forward[i] = max(arr[i], forward[i - 1] + arr[i]);
            ans = max(ans, forward[i]);
        }

        // Backward Kadane
        backward[n - 1] = arr[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            backward[i] = max(arr[i], backward[i + 1] + arr[i]);
        }

        // Remove one element
        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, forward[i - 1] + backward[i + 1]);
        }

        return ans;
    }
};