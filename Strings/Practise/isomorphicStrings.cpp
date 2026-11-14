//Given two strings s1 and s2 consisting only of lowercase English letters and having the same length, check whether they are isomorphic. Two strings are isomorphic if:
// 1. Each character in s1 must always map to the same character in s2.
// 2. No two different characters in s1 can map to the same character in s2.
// 3. A character may map to itself.
// Return true if s1 and s2 are isomorphic, otherwise return false.

// Examples:
// Input: s1 = "aab", s2 = "xxy"
// Output: true
// Explanation: Each character in s1 can be consistently mapped to a unique character in s2 (a -> x, b -> y).

#include <bits/stdc++.h>
using namespace std;

bool areIsomorphic(string &s1, string &s2) {
    if (s1.length() != s2.length()) {
        return false;
    }

    unordered_map<char, char> map1;
    unordered_map<char, char> map2;

    for (int i = 0; i < s1.length(); i++) {
        char c1 = s1[i];
        char c2 = s2[i];

        if (map1.find(c1) != map1.end()) {
            if (map1[c1] != c2) {
                return false;
            }
        } else {
            map1[c1] = c2;
        }

        if (map2.find(c2) != map2.end()) {
            if (map2[c2] != c1) {
                return false;
            }
        } else {
            map2[c2] = c1;
        }
    }

    return true;
}