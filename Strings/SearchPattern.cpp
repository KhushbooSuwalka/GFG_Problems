//Given two strings, a text string txt and a pattern string pat, both consisting of lowercase English alphabets. Return the starting indices (0-based) of all the occurrences of the pattern string pat in the text string txt.
// Note: Return an empty list in case of no occurrences of pattern.

// Examples:
// Input: txt = "geeksforgeeks", pat = "geek"
// Output: [0, 8]
// Explanation: The string "geek" occurs twice in txt, one starts at index 0 and the other at index 8.

#include <bits/stdc++.h>
using namespace std;

// Using KMP (Knuth-Morris-Pratt) algorithm for pattern searching

class Solution {
public:

    // LPS array banayenge
    vector<int> getLPS(string pat) {
        int m = pat.size();

        vector<int> lps(m, 0);

        int len = 0;
        int i = 1;

        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    vector<int> search(string &pat, string &txt) {
        vector<int> ans;

        int n = txt.size() , m = pat.size();

        // LPS array
        vector<int> lps = getLPS(pat);

        int i = 0;  // txt pointer
        int j = 0;  // pat pointer

        while (i < n) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }

            // Pattern completely match ho gaya
            if (j == m) {
                ans.push_back(i - j);

                // Next overlapping occurrence ke liye
                j = lps[j - 1];
            }

            // Characters mismatch
            else if (i < n && txt[i] != pat[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                }
                else {
                    i++;
                }
            }
        }

        return ans;
    }
};