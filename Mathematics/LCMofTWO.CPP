//Given two positive integers a and b, find the Least Common Multiple (LCM) of the two numbers.

// Examples:
// Input: a = 12, b = 18
// Output: 36
// Explanation: LCM of 12 and 18 is 36

#include<bits/stdc++.h>
using namespace std;

int lcm(int a, int b) {
    // larger value
    int g = max(a, b);
    
    // Smaller value
    int s = min(a, b);
    
    for (int i = g; i <= a * b; i += g) {
        if (i % s == 0)
            return i;
    }
}

// Formula :- a x b = LCM(a, b) * GCD (a, b)