// Given an array arr[] and a target, your task is to find all unique combinations in the array where the sum of the elements is equal to target. Each element in arr[] can be used at most once in the combination.
// Note: You can return your answer in any order, the driver code will print them in sorted order.
// Test cases are generated such that number of unique combination does not exceed 106.

// Examples:
// Input: arr[] = [1, 2, 3], target = 5
// Output: [[2, 3]]
// Explanation: There is only one unique combinations whose sum is equal to the target.

// Recursion tree will look like this for arr[] = [1, 2, 3] and target = 4
//                  []
//             target = 4
//             /        \
//           1            2
//          /              \
//       [1]              [2]
//      target 3          target 2
//      /     \             |
//     2       3            2
//    /         \            |
// target 1    target 0    target 0
//   X          [1,3]       [2,2]

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void solve(vector<int> &arr, int target, vector<int> &current, 
               vector<vector<int>> &ans, int index){
        
        // Target achieved
        if (target == 0) {
            ans.push_back(current);
            return;
        }
        
        // No elements left
        if (index == arr.size()) {
            return;
        }
        
        // Current element is bigger than target
        if (arr[index] > target) {
            return;
        }
        
        // TAKE current element
        current.push_back(arr[index]);

        // Stay at same index because we can use the same number again
        solve(arr, target - arr[index], current, ans,index);

        // Backtrack
        current.pop_back();

        // DON'T TAKE current element
        solve(arr, target, current, ans, index+1);

    }
    
    vector<vector<int>> targetSumComb(vector<int> &arr, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        
        sort(arr.begin(), arr.end());
        
        solve(arr,target,curr,ans,0);
        
        return ans;
    }
};