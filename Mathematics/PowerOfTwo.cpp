//Given a non-negative integer n, return true if it is a power of 2. Otherwise, return false.  

// Examples:
// Input: n = 8
// Output: true
// Explanation: 8 is equal to 2 raised to 3 (23 = 8).

#include<bits/stdc++.h>
using namespace std;

// Approach 1 :- 

class Solution {
public:
    bool isPowerofTwo(int n) {
        
        if (n == 0)
            return false;
        
        while (n % 2 == 0) {
            n = n / 2;
        }
        
        return n == 1;
    }
};

// Approach 2 :- Using Count of Set Bits

bool isPowerofTwo(int n) {
    if (n <= 0)
        return false;
    
    // Count set bits
    int count = 0;
    while (n > 0) {
        if (n & 1)
            count++;
        n = n >> 1;
    }
    
    // If count of set bits is 1, then n is a power of 2
    return (count == 1);
}

// Approach 3 :- 

bool isPowerofTwo(int n) { 
    // Check if n is positive and n & (n-1) is 0
    return (n > 0) && ((n & (n-1)) == 0);
}