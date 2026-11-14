//Given a string s of lowercase English letters, you can swap all occurrences of any two distinct characters at most once. Return the lexicographically smallest string after this operation.
// Examples:
// Input: s = "ccad"
// Output: "aacd"
// Explanation: In ccad, we choose a and c and after doing the replacement operation once, we get aacd and this is the lexicographically smallest string possible.

#include<bits/stdc++.h>
using namespace std;

// Approach 1 :- 

class Solution {
public:
    string chooseSwap(string &s) {
        bool present[26] = {false};

        // Mark all characters present in string
        for(char ch : s) {
            present[ch - 'a'] = true;
        }

        // Find the first character to swap
        for(int i = 0; i < s.length(); i++) {
            // Check smaller characters
            for(char ch = 'a'; ch < s[i]; ch++) {
                if(present[ch - 'a']) {
                    // Swap both characters everywhere
                    char first = s[i];
                    char second = ch;

                    for(int j = 0; j < s.length(); j++) {
                        if(s[j] == first) {
                            s[j] = second;
                        }
                        else if(s[j] == second) {
                            s[j] = first;
                        }
                    }

                    return s;
                }
            }
        }

        return s;
    }
};

// Approach 2 :- submitted

class Solution {
public:
    string chooseSwap(string& s) {
        int first[26];

        for(int i = 0; i < 26; i++) {
            first[i] = -1;
        }

        for(int i = 0; i < s.length(); i++) {
            if(first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
        }

        for(int i = 0; i < s.length(); i++) {
            int current = s[i] - 'a';

            for(int j = 0; j < current; j++) {
                if(first[j] > i) {
                    char a = s[i];
                    char b = 'a' + j;

                    for(int k = 0; k < s.length(); k++) {
                        if(s[k] == a) {
                            s[k] = b;
                        }
                        else if(s[k] == b) {
                            s[k] = a;
                        }
                    }

                    return s;
                }
            }
        }

        return s;
    }
};