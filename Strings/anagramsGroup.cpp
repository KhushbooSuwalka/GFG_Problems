//Group Anagrams Together
//Given an array arr[] of strings, group all anagrams together. Two strings are anagrams if they contain the same characters with the same frequencies, possibly in a different order.
//Return a 2D array, where each inner array contains a group of anagrams. The relative order of strings within each group should be the same as their order in arr.

#include<bits/stdc++.h>
using namespace std;

//Approach 1 :- Compare Every Pair of Strings

class Solution {
public:

    bool areAnagrams(string a, string b) {
        if (a.size() != b.size()) {
            return false;
        }

        // Sort both strings
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        // If sorted strings are same,they are anagrams
        return a == b;
    }

    vector<vector<string>> anagrams(vector<string>& arr) {
        int n = arr.size();
        vector<vector<string>> ans;

        // Keep track of already grouped strings
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            // If already included in a group , skip it
            if (visited[i]) {
                continue;
            }

            vector<string> group;

            // Start a new group
            group.push_back(arr[i]);

            // Mark current string as visited
            visited[i] = true;

            // Compare arr[i] with remaining strings
            for (int j = i + 1; j < n; j++) {

                if (!visited[j] && areAnagrams(arr[i], arr[j])) {
                    group.push_back(arr[j]);
                    visited[j] = true;
                }

            }

            // Add group to answer
            ans.push_back(group);
        }

        return ans;
    }
};

//Approach 2 :- Using Sorted Words as Keys

class Solution {
public:
    vector<vector<string>> anagrams(vector<string>& arr) {

        // Map sorted string -> group of anagrams
        map<string, vector<string>> mp;

        // Process every word
        for (string word : arr) {

            // Create a copy of word
            string key = word;

            // Sort characters
            sort(key.begin(), key.end());

            // Add original word to its group
            mp[key].push_back(word);
        }

        // Store final answer
        vector<vector<string>> ans;

        // Take each group from map
        for (auto &it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

//Approach 3 :- Using Frequency Array as Keys

class Solution {
public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // Frequency array as key
        map<vector<int>, vector<string>> mp;

        for (string word : arr) {

            // Frequency of 26 lowercase letters
            vector<int> freq(26, 0);

            // Count each character
            for (char ch : word) {
                freq[ch - 'a']++;
            }

            // Put original word into its group
            mp[freq].push_back(word);
        }

        vector<vector<string>> ans;

        for (auto &it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};