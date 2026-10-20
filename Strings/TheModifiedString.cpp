//Given a string s, a string is considered valid if it does not contain three consecutive identical characters. You may insert characters at any position in the string.
// Return the minimum number of insertions required to make s valid.

// Examples:
// Input: s = "aabbbcc"
// Output: 1
// Explanation: In "aabbbcc" 3 b's occur consecutively, we need to add a 'd', and Hence, the output will be "aabbdbcc".

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int modified(string& s) {
        int ans = 0;
        int count = 1;

        for(int i = 1; i < s.length(); i++) {
            if(s[i] == s[i - 1]) {
                count++;
            }
            else {
                count = 1;
            }
            
            if(count == 3) {
                ans++;
                count = 1;
            }
        }

        return ans;
    }
};