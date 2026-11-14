//Given two numbers as strings s1 and s2. Calculate their Product.
// Note: The numbers can be negative and You are not allowed to use any built-in function or convert the strings to integers. There can be zeros in the begining of the numbers. You don't need to specify '+' sign in the begining of positive numbers.

// Examples:
// Input: s1 = "0033", s2 = "2"
// Output: "66"
// Explanation: 33 * 2 = 66

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiplyStrings(string& s1, string& s2) {
        bool negative = false;

        if(s1[0] == '-') {
            negative = !negative;
            s1 = s1.substr(1);
        }

        if(s2[0] == '-') {
            negative = !negative;
            s2 = s2.substr(1);
        }

        int n = s1.size();
        int m = s2.size();

        // Remove leading zeros
        int i = 0;
        while(i < n && s1[i] == '0') {
            i++;
        }
        s1 = s1.substr(i);

        i = 0;
        while(i < m && s2[i] == '0') {
            i++;
        }
        s2 = s2.substr(i);

        // If either number is zero
        if(s1.empty() || s2.empty()) {
            return "0";
        }

        n = s1.size();
        m = s2.size();

        vector<int> result(n + m, 0);

        // Multiply digit by digit
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                int mul = (s1[i] - '0') * (s2[j] - '0');
                int sum = mul + result[i + j + 1];
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        // Convert result array into string
        string ans = "";

        i = 0;
        while(i < result.size() && result[i] == 0) {
            i++;
        }

        while(i < result.size()) {
            ans += (result[i] + '0');
            i++;
        }

        if(negative) {
            ans = "-" + ans;
        }

        return ans;
    }
};