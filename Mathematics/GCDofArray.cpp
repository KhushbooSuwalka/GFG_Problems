//Given an array of n positive integers, find the GCD of all the array elements.

// Example :
// Input: n = 3, arr = [1, 2, 3]
// Output: 1
// Explanation: GCD of 1,2,3 is 1.

#include<bits/stdc++.h>
using namespace std;

// Recursive function to return gcd of a and b
int FindGCD(int a, int b) {
    if (a == 0)
        return b;
    return FindGCD(b % a,a);
}

// Function to find gcd of array of numbers
int gcd(int n,vector<int> &arr) {
    int res = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        res = FindGCD(arr[i], res);

        // If res becomes 1 at any iteration then it remains 1, So no need to check further
        if (res == 1)
            return 1;
    }
    return res;
}