// Given an integer n, determine position of the only set bit (1) in its binary representation. The position is counted starting from 1 at the least significant bit (LSB).
// If n contains exactly one set bit, return its position.
// If n contains no set bits or more than one set bit, return -1.

// Examples:
// Input: n = 2
// Output: 2
// Explanation: 2 is represented as "10" in binary. It has only one set bit, which is at position 2.

#include<bits/stdc++.h>
using namespace std;

// Approach 1 :- 

int findPosition(int n){
    // Check if n has exactly one set bit
    if (n == 0 || (n & (n - 1)) != 0)
        return -1;

    int pos = 1;
    int val = 1;
    while ((val & n) == 0){
        // shifting left
        val = val << 1;
        pos++;
    }
    return pos;
}

// Approach 2 :- 

int findPosition(int n){
    // Check if n has exactly one set bit
    if (n == 0 || (n & (n - 1)) != 0)
        return -1;

    int pos = 1;
    while ((n & 1) == 0){
        // Shifting right
        n = n >> 1;
        pos++;
    }
    return pos;
}