// Given a string s consisting of lowercase English letters, check whether it can be rearranged such that no two adjacent characters are the same.
// Return true if possible, otherwise, return false.

// Examples:
// Input: s = "aaabc"
// Output: true
// Explanation: "aaabc" can rearranged to "abaca" or "acaba" as no two adjacent characters are same in the output string.

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Using Max-Heap (Priority Queue)
// Time Complexity: O(N * log(k)) where k <= 26 is number of distinct characters
// Space Complexity: O(k) for the priority queue and frequency array
class Solution {
  public:
    bool canRearrange(string& s) {
        // Count frequency of each character
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        
        // Max heap : {frequency, character}
        priority_queue<pair<int, char>> pq;
        for (char c = 'a'; c <= 'z'; c++) {
            if (freq[c - 'a'] > 0) {
                pq.push({freq[c - 'a'], c});
            }
        }
        
        char prev = '#';
        while (!pq.empty()) {
            pair<int, char> top1 = pq.top();
            pq.pop();
            int count = top1.first;
            char ch = top1.second;
            
            // Cannot use same character as prev
            if (ch == prev) {
                // No other character available
                if (pq.empty()) return false;
                
                pair<int, char> top2 = pq.top();
                pq.pop();
                int count2 = top2.first;
                char ch2 = top2.second;
                
                // Use second most frequent character
                prev = ch2;
                count2--;
                
                if (count2 > 0) {
                    pq.push({count2, ch2});
                }
                
                // Put the first character back
                pq.push({count, ch});
            } else {
                prev = ch;
                count--;
                
                if (count > 0) {
                    pq.push({count, ch});
                }
            }
        }
        
        return true;
    }
};

class Solution{
    public:
    // Approach 2: Optimal Frequency Check (Pigeonhole Principle)
    // Time Complexity: O(N), Space Complexity: O(1)
    // A string can be rearranged if and only if the most frequent character does not exceed (n + 1) / 2 occurrences.
    bool canRearrangeOptimal(string& s) {
        int n = s.length();
        vector<int> freq(26, 0);
        int maxFreq = 0;
        
        for (char ch : s) {
            freq[ch - 'a']++;
            maxFreq = max(maxFreq, freq[ch - 'a']);
        }
        
        return maxFreq <= (n + 1) / 2;
    }
};

// int main() {
//     Solution sol;

//     string s1 = "aaabc";
//     cout << "Input: " << s1 << " -> " << (sol.canRearrange(s1) ? "true" : "false") << endl;

//     string s2 = "aaab";
//     cout << "Input: " << s2 << " -> " << (sol.canRearrange(s2) ? "true" : "false") << endl;

//     return 0;
// }