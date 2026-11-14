//Given two strings s1 and s2 consisting of lowercase English alphabets, and an integer value k, return true if two strings are k-anagrams of each other. Otherwise, return false.
//Two strings are called k-anagrams if both of the below conditions are true.
//1. Both have same number of characters.
//2. Two strings can become anagram by changing at most k characters in a string.

//Example:
//Input: s1 = "fodr", s2 = "gork", k = 2
//Output: true
//Explanation: We can change 'f' -> 'g' and 'd' -> 'k' in s1.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool areKAnagrams(string& s1, string& s2, int k) {
        if (s1.length() != s2.length()) {
            return false; // Condition 1: Both strings must have the same length
        }

        unordered_map<char, int> freqMap;
        
        // Count frequency of characters in s1
        for (char c : s1) {
            freqMap[c]++;
        }

        int changesNeeded = 0;

        // Compare with characters in s2
        for (char c : s2) {
            if (freqMap[c] > 0) {
                freqMap[c]--; // Decrease count if character is found
            } else {
                changesNeeded++; // Character not found, need to change
            }
        }

        // Check if the number of changes needed is within k
        return changesNeeded <= k;
    }
};