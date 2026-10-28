//You are given a number n. You need to find the digital root of n. Digital Root of a number is the recursive sum of its digits until we get a single digit number.

// Examples :
// Input: n = 1
// Output:  1
// Explanation: Digital root of 1 is 1
// Input: n = 99999
// Output: 9
// Explanation: Sum of digits of 99999 is 45 which is not a single digit number, hence sum of digit of 45 is 9 which is a single digit number.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digitalRoot(int n) {
        while (n >= 10) {
            int sum = 0;

            while (n > 0) {
                sum += n % 10;
                n = n / 10;
            }

            n = sum;
        }
        return n;
    }
};