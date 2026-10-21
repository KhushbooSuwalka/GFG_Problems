//Given a string s, convert it into a 32-bit signed integer (similar to the atoi() function) without using any built-in conversion functions.
// The conversion follows these rules:
// Ignore Leading Whitespaces: Skip all leading whitespace characters.
// Check Sign: If the next character is either '+' or '-', take it as the sign of the number. If no sign is present, assume the number is positive.
// Read Digits: Read the digits and ignore any leading zeros. Stop reading when a non-digit character is encountered or the end of the string is reached. If no digits are found, return 0.
// Handle Overflow: If the number exceeds the range of a 32-bit signed integer:
// Return 2³¹ − 1 (i.e., 2147483647) if it is greater than the maximum value.
// Return −2³¹ (i.e., -2147483648) if it is smaller than the minimum value.
// Return the final integer value.

// Examples:
// Input: s = "-123"
// Output: -123
// Explanation: It is possible to convert -123 into an integer so we returned in the form of an integer

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string& s) {
        int i = 0;
        int n = s.size();

        // 1. Leading spaces skip karo
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Sign check karo
        int sign = 1;

        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            i++;
        }

        // 3. Number build karo
        long long num = 0;

        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
            num = num * 10 + digit;

            // 4. Overflow check
            if (sign * num > INT_MAX) {
                return INT_MAX;
            }

            if (sign * num < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return sign * num;
    }
};