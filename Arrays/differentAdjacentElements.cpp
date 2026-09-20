//Different Adjacent Elements
//Given an array arr[] of integers, determine whether it is possible to rearrange the array using any number of swaps between adjacent elements - so that no two adjacent elements in the resulting array are equal.

// Examples:
// Input: arr[] = [1, 1, 2]
// Output: true
// Explanation: Swapping the last two elements gives [1, 2, 1], where no two adjacent elements are equal.

#include<bits/stdc++.h>
using namespace std;

bool distinctAdjacent(vector<int> &arr) {
    int n = arr.size();

    // Count the frequency of every element
    unordered_map<int, int> freq;
    for (int num : arr) {
        freq[num]++;
    }

    // Find the maximum frequency among all elements
    int maxFreq = 0;
    for (auto &entry : freq) {
        maxFreq = max(maxFreq, entry.second);
    }

    // Rearrangement is possible only if the maximum frequency
    // does not exceed ceil(n / 2)
    return maxFreq <= (n + 1) / 2;
}