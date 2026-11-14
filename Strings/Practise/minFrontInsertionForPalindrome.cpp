//Given a string s, the task is to find the minimum characters to be added at the front to make the string palindrome.

// Examples:
// Input: s = "abc"
// Output: 2
// Explanation: Add 'b' and 'c' at front of the above string to make it palindrome: "cbabc"

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChar(string& s) {
        string rev = s;

        // Reverse the original string
        reverse(rev.begin(), rev.end());

        // Combine original + separator + reversed string
        string temp = s + "#" + rev;

        int n = temp.length();
        vector<int> lps(n, 0);

        // Build LPS array
        int len = 0;
        for(int i = 1; i < n; i++) {
            while(len > 0 && temp[i] != temp[len]) {
                len = lps[len - 1];
            }

            if(temp[i] == temp[len]) {
                len++;
            }

            lps[i] = len;
        }

        // Original length - longest palindromic prefix
        return s.length() - lps[n - 1];
    }
};