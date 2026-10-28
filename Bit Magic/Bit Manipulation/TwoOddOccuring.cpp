//Given an unsorted array, arr[] of positive numbers that contains even number of occurrences for all numbers except two numbers. Return that two numbers in decreasing order which has odd occurrences.

// Examples:
// Input: arr = [4, 2, 4, 5, 2, 3, 3, 1]
// Output: [5, 1] 
// Explanation: 5 and 1 have odd occurrences.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> twoOddNum(vector<int>& arr) {
       int x = 0;

       // XOR all elements
       for (int num : arr) {
           x = x ^ num;
       }

       // Find rightmost set bit
       int bit = x & (-x);

       int a = 0, b = 0;

       // Divide elements into two groups
       for (int num : arr) {
           if (num & bit) {
               a = a ^ num;
           }
           else {
               b = b ^ num;
           }
       }

       // Decreasing order
       if (a < b)
           swap(a, b);

       return {a, b};
    }
};