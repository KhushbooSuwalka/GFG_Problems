//Given a string s consisting of distinct lowercase characters, determine its rank among all its permutations when those are arranged in lexicographically sorted order.
// Note: The rank of a string is its position (starting from 1) in the sorted list of all its permutations.

// Examples:
// Input: s = "abc"
// Output: 1
// Explanation: All permutations of "abc" arranged in lexicographical order are: [abc, acb, bac, bca, cab, cba]. Since "abc" appears first in this list, its rank is 1.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findRank(string& s) {
        int n = s.length();

        long long fact[19];
        fact[0] = 1;

        for(int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
        }

        bool present[26] = {false};
        bool used[26] = {false};

        // Mark characters present in original string
        for(char ch : s) {
            present[ch - 'a'] = true;
        }

        long long rank = 1;

        for(int i = 0; i < n; i++) {
            int count = 0;

            for(int j = 0; j < s[i] - 'a'; j++) {
                if(present[j] && !used[j]) {
                    count++;
                }
            }

            rank += count * fact[n - i - 1];
            used[s[i] - 'a'] = true;
        }

        return rank;
    }
};