//Given an array arr[] of unique elements. Generate all possible permutations of the elements in the array.
// Note: You can return the permutations in any order, the driver code will print them in sorted order.

// Examples:
// Input: arr[] = [1, 2, 3]
// Output: [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]
// Explanation: There are 6 possible permutations (3! = 6) of the array.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    void solve(vector<int>& arr, vector<int>& curr,
               vector<vector<int>>& ans, vector<bool>& used) {

        int n = arr.size();

        // If permutation is complete
        if (curr.size() == n) {
            ans.push_back(curr);
            return;
        }

        // Try every element
        for (int i = 0; i < n; i++) {

            // If already used, don't choose it
            if (used[i])
                continue;

            // Choose
            curr.push_back(arr[i]);
            used[i] = true;

            // Go to next position
            solve(arr, curr, ans, used);

            // Backtrack
            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteDist(vector<int>& arr) {

        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> used(arr.size(), false);

        solve(arr, curr, ans, used);

        return ans;
    }
};