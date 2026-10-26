//Given two positive integers a and b, find GCD of a and b.
// Note: Don't use the inbuilt gcd function

// Examples:
// Input: a = 20, b = 28
// Output: 4
// Explanation: GCD of 20 and 28 is 4

#include<bits/stdc++.h>
using namespace std;

// Approach 1:-

int gcd(int a, int b){
    // Everything divides 0
    if (a == 0 || b == 0)
        return max(a, b);

    // Find Minimum of a and b
    int result = min(a, b);
    while (result > 0){
        if (a % result == 0 && b % result == 0){
            break;
        }
        result--;
    }

    // Return gcd of a and b
    return result;
}

// Approach 2:- Euclidean Algorithm 

int gcd(int a, int b){
    // Everything divides 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // Base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}

// Approach 3:- 

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

// Approach 4:- Built-in function

int gcd(int a, int b){
    return __gcd(a, b);
}