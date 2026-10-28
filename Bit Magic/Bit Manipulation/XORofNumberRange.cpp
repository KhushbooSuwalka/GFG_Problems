//Given two integers l and r, find the XOR of elements of the range [l, r].

// Example:
// Input: l = 4, r = 8 
// Output: 8 
// Explanation: The value of (4 ^ 5 ^ 6 ^ 7 ^ 8) = 8.

#include <bits/stdc++.h>
using namespace std;

// Approach 1:-

class Solution {
  public:
    int findXOR(int l, int r) {
        int ans=0;
        for(int i=l;i<=r;i++){
            ans^=i;
        }
        return ans;
    }
};

// Approach 2:-

class Solution {
  public:
    int xorUpto(int n) {
        if (n % 4 == 0)
            return n;

        else if (n % 4 == 1)
            return 1;

        else if (n % 4 == 2)
            return n + 1;

        else
            return 0;
    }
    
    int findXOR(int l, int r) {
        return xorUpto(r) ^ xorUpto(l - 1);
    }
};