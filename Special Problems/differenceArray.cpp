//You are given an array arr[] and a  2D array opr[][], where each opr[i] denotes an operation in the format [l, r, v].
// For each operation [l, r, v], you need to add the value v to all elements of the array from index l to r (both inclusive).
// Apply all operations sequentially in the given order, and return the final updated array.

// Examples:
// Input: arr[] = [2, 3, 5, 6, 7], opr[][] = [[2, 4, 2], [3, 4, -1]]
// Output: [2, 3, 7, 7, 8]
// Explanation:
// Operation [2, 4, 2] : Add 2 to indices 2 to 4 → [2, 3, 7, 8, 9] 
// Operation [3, 4, -1] : Subtract 1 from indices 3 to 4 → [2, 3, 7, 7, 8] 
// Final array is [2, 3, 7, 7, 8].

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> diffArray(vector<int>& arr, vector<vector<int>>& opr) {
        int n = arr.size();

        // Difference array
        vector<int> diff(n + 1, 0);

        // Mark all operations
        for (auto &op : opr) {
            int l = op[0];
            int r = op[1];
            int v = op[2];

            diff[l] += v;
            diff[r + 1] -= v;
        }

        // Apply prefix sum
        int add = 0;

        for (int i = 0; i < n; i++) {
            add += diff[i];
            arr[i] += add;
        }

        return arr;
    }
};