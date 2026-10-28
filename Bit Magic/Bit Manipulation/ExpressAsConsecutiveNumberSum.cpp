//Given a number n, find whether n can be expressed as sum of two or more consecutive positive numbers.

// Examples :
// Input: n = 10
// Output: true
// Explanation: 10 can be expressesd as 1 + 2 + 3 + 4.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isSumOfConsecutive(int n) {
        // 1 cannot be represented
        if (n == 1){
            return false;
        }

        // Check if n is power of 2
        if ((n & (n - 1)) == 0){
            return false;
        }

        return true;
    }
};