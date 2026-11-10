//Given a non-negative integer n, convert its binary representation into the corresponding Gray code and return the decimal value of the resulting Gray code.

// Examples:
// Input: n = 7
// Output: 4
// Explanation: The binary representation of 7 is 111. Its Gray code representation is 100, whose decimal value is 4.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int binaryToGray(int n) {
        int res = n >> 1;
        return n ^ res;
    }
};