//Last Digit of a^b
//Given two integers a and b in the form of strings. Return the last digit of a^b.

// Examples:
// Input: a = "3", b = "10"
// Output: 9
// Explanation: 3^10 = 59049. Last digit is 9.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLastDigit(string& a, string& b) {
        // Last digit of a
        int x = a[a.size() - 1] - '0';

        // If exponent is 0
        if (b == "0")
            return 1;

        // Calculate b % 4
        int rem = 0;

        for (int i = 0; i < b.size(); i++) {
            rem = (rem * 10 + (b[i] - '0')) % 4;
        }

        // If remainder is 0, take power as 4
        if (rem == 0)
            rem = 4;

        // Calculate last digit
        int ans = 1;

        for (int i = 1; i <= rem; i++) {
            ans = (ans * x) % 10;
        }

        return ans;
    }
};