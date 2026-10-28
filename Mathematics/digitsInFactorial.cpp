//Given an integer n, find the number of digits in the value of n factorial. 

// Examples :
// Input: n = 5
// Output: 3
// Explanation: Factorial of 5 is 120. Number of digits in 120 is 3 (1, 2, and 0)

#include <bits/stdc++.h>
using namespace std;

// Approach 1:-

int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int digitsInFactorial(int n) {
    // Factorial exists only for n >= 0
    if (n < 0)
        return 0;

    // Calculate factorial
    int fact = factorial(n);

    // Count digits
    int digits = 0;

    do {
        digits++;
        fact /= 10;
    } while (fact != 0);

    return digits;
}

// Approach 2:-

class Solution {
public:
    int digitsInFactorial(int n) {
        if (n < 0)
            return 0;

        double sum = 0;

        for (int i = 1; i <= n; i++) {
            sum += log10(i);
        }

        return floor(sum) + 1;
    }
};