//Given a string s, generate all possible subsequences of the string (including the empty subsequence) and return them in lexicographical order.
// A subsequence is obtained by deleting zero or more characters from the string without changing the relative order of the remaining characters.

// Examples:
// Input : s = "abc"
// Output: ["", "a", "ab", "abc", "ac", "b", "bc", "c"]
// Explanation: There are a total of 8 non-empty subsequences for the given string. 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> powerSet(string& s) {
        vector<string> result;
        int n = s.length();
        // Generate all possible subsequences using bit manipulation
        for (int i = 0; i < (1 << n); i++) {
            string subseq = "";
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    subseq += s[j];
                }
            }
            result.push_back(subseq);
        }
        // Sort the subsequences in lexicographical order
        sort(result.begin(), result.end());
        return result;
    }
};
