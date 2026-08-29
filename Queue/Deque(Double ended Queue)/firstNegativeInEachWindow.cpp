//First Negative in Windows of Size K
//Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.
// Note: If a window does not contain a negative integer, then return 0 for that window.

// Examples:
// Input: arr[] = [-8, 2, 3, -6, 10] , k = 2
// Output: [-8, 0, -6, -6]
// Explanation:
// Window [-8, 2] First negative integer is -8.
// Window [2, 3] No negative integers, output is 0.
// Window [3, -6] First negative integer is -6.
// Window [-6, 10] First negative integer is -6.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;
        
        deque<int> dq;

        for(int i = 0; i < n; i++) {

            // 1. Remove indices which are outside the window
            while(!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // 2. Add current index only if element is negative
            if(arr[i] < 0) {
                dq.push_back(i);
            }

            // 3. Window is ready
            if(i >= k - 1) {
                
                // If deque is empty, no negative number
                if(dq.empty()) {
                    ans.push_back(0);
                }
                else {
                    // Front = first negative element
                    ans.push_back(arr[dq.front()]);
                }
            }
        }

        return ans;
    }
};