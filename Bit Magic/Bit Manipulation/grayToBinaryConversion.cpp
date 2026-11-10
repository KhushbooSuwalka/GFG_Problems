//Given a non-negative integer n, whose binary representation represents a Gray code, convert this Gray code to its equivalent binary number and return the decimal value of that binary number. 

// Examples :
// Input: n = 4
// Output: 7
// Explanation: The binary representation of 4 is 100. Treating 100 as a Gray code, its corresponding binary representation is 111, whose decimal value is 7.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int grayToBinary(int n) {
        int res = 0;
        while (n > 0) {
            res ^= n;
            n >>= 1;
        }
        return res;
    }
};