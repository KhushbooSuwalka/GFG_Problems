//Minimum Time to Burst Balloons
// Given an array positions[] denoting the positions of balloons on a number line, Geek wants to burst exactly k of these balloons.
// Geek starts at coordinate 0 and can move left or right along the number line at a speed of 1 unit per second. He can burst a balloon instantly when he is at the same position as that of the balloon. Determine the minimum time required for geek to burst exactly k balloons.

// Examples:
// Input: k = 2, positions = [2,-1, 4]
// Output: 4
// Explanation: Geek can move from 0 to -1 (1 second), burst the balloon at -1 (0 seconds), move from -1 to 2 (3 seconds) and burst the balloon at 2 (0 seconds). Total time is 4 seconds.
// Input: k = 3, positions = [-3, 0, 1, -2, 5]
// Output: 3
// Explanation: Geek can burst the balloon at 0 (0 seconds), move from 0 to -2 (2 seconds), burst the balloon at -2 (0 seconds), move from -2 to -3 (1 second) and burst the balloon at -3 (0 seconds). Total time is 3 seconds.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minTime(int k, vector<int>& positions) {
        sort(positions.begin(), positions.end());
        int n = positions.size();
        int ans = INT_MAX;
        for (int i = 0; i <= n - k; i++) {
            int left = positions[i];
            int right = positions[i + k - 1];
            int time = min(abs(left), abs(right)) + (right - left);
            ans = min(ans, time);
        }
        return ans;
    }
};