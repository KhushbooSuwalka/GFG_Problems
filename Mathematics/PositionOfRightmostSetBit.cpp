// Given an integer n, Return the position of the first set bit from right to left in the binary representation n. If no set bits present , then return 0.
// Note: Position of rightmost bit is 1.

// Examples:
// Input: n = 18
// Output: 2
// Explanation: Binary representation of 18 is 10010, hence position of first set bit from right is 2.

#include<bits/stdc++.h>
using namespace std;

// Approach 1 :- 

int getFirstSetBit(int n) {
    // If no set bit
    if (n == 0) return 0;

    int pos = 1;

    // Left shift a mask and check each bit
    while ((n & (1 << (pos - 1))) == 0) {
        pos++;
    }

    return pos;
}

// Approach 2 :- 

int getFirstSetBit(int n) {
    // If no set bit 
    if (n == 0) return 0;
    
    int res = 1;
    
    // Right shift and check LSB
    while (!(n & 1)) {
        n = n >> 1;
        res++;
    }
    
    return res;
}

// Approach 3 :-

int getFirstSetBit(int n) { 
    // If no set bit 
    if (n == 0) return 0;
    return __builtin_ffs(n);
}