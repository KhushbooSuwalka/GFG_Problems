//You are given an array arr[] of positive integers (which may contain duplicates), your task is to find all the unique or distinct subsets of the array.
// Note: You can return the subsets in any order, the driver code will print them in sorted order.

// Examples:
// Input: arr[] = [1, 5, 6]
// Output: [[], [1], [1, 5], [1, 5, 6], [1, 6], [5], [5, 6], [6]]
// Explanation: The number of all the possible subsets will be 2n.
// Now the unique subsets are [], [1], [1, 5], [1, 5, 6], [1, 6], [5], [5, 6], [6].

#include <bits/stdc++.h>
using namespace std;

// Approach 1 :- By Bit Masking

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& arr) {  
        sort(arr.begin(), arr.end());

        set<vector<int>> st;
        int n = arr.size();

        for (int mask = 0; mask < (1 << n); mask++) {   
            vector<int> temp;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    temp.push_back(arr[i]);
                }
            }

            st.insert(temp);
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

// Approach 2 :- By backtracking

class Solution {
public:
    void solve(vector<int>& arr, int index, vector<int>& current, vector<vector<int>>& ans) {
        ans.push_back(current);

        for (int i = index; i < arr.size(); i++) {
            // Same level par duplicate skip
            if (i > index && arr[i] == arr[i - 1])
                continue;

            current.push_back(arr[i]);

            solve(arr, i + 1, current, ans);

            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;
        vector<int> current;

        solve(arr, 0, current, ans);

        return ans;
    }
};