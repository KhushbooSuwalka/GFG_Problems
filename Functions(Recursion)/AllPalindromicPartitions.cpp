//Given a string s, find all possible ways to partition it such that every substring in the partition is a palindrome.

// Examples:
// Input: s = "geeks"
// Output: [[g, e, e, k, s], [g, ee, k, s]]
// Explanation: [g, e, e, k, s] and [g, ee, k, s] are the only partitions of "geeks" where each substring is a palindrome.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    // Check whether s[start...end] is palindrome
    bool isPalindrome(string &s, int start, int end) {

        while(start < end) {
            if(s[start] != s[end])
                return false;

            start++;
            end--;
        }

        return true;
    }

    void solve(string &s, int index, vector<string>& current, vector<vector<string>>& ans) {

        // If we reached the end of string
        if(index == s.size()) {
            ans.push_back(current);
            return;
        }

        // Try every possible substring starting from index
        for(int i = index; i < s.size(); i++) {

            // Take s[index...i] only if it is palindrome
            if(isPalindrome(s, index, i)) {

                // Choose
                current.push_back(s.substr(index, i - index + 1));

                // Solve remaining string
                solve(s, i + 1, current, ans);

                // Backtrack
                current.pop_back();
            }
        }
    }

    vector<vector<string>> palinParts(string &s) {
        vector<vector<string>> ans;
        vector<string> current;

        solve(s, 0, current, ans);
        return ans;
    }
};