//Given an array arr[] of integers and two integers a and b, find the maximum possible sum of a contiguous subarray whose length is at least a and at most b.
//Note: It is guaranteed that the maximum subarray sum will fit in a 32-bit signed integer.

// Examples:
// Input: arr[] = [4, 5, -1, -2, 6], a = 2, b = 4
// Output: 9
// Explanation: The subarray [4, 5] has length 2 and sum 9, which is the maximum among all subarrays of length between 2 and 4.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size();

        // Prefix sum
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + arr[i];
        }

        deque<int> dq;
        long long ans = LLONG_MIN; //ans = -infinity

        for (int i = a; i <= n; i++) {

            int idx = i - a;

            // Remove larger prefix sums from the back because we only need
            // the smallest prefix sum to get the maximum subarray sum.
            while (!dq.empty() && pref[dq.back()] >= pref[idx]) {
                dq.pop_back();
            }
            dq.push_back(idx);

            // Remove indices that would make the subarray length greater than b.
            while (!dq.empty() && dq.front() < i - b) {
                dq.pop_front();       //For every i, we need: i-b <= starting_index <= i-a
            }

            // Current subarray sum = pref[i] - smallest valid prefix sum.
            ans = max(ans, pref[i] - pref[dq.front()]);
        }

        return (int)ans;
    }
};

//Always remeber this for this ques :-
//Deque front = smallest valid prefix sum → subtract it from current prefix sum → maximum subarray sum.