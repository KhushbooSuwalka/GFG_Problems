//Longest Common Prefix of Strings
//Given an array of strings arr[]. Return the longest common prefix among each and every strings present in the array. If there's no prefix common in all the strings, return "".

#include<bits/stdc++.h>
using namespace std;

//Approach 1: Using Sorting

class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        // Sort all strings
        sort(arr.begin(), arr.end());

        // First and last string
        string first = arr[0];
        string last = arr[arr.size() - 1];

        string ans = "";

        // Compare characters
        for (int i = 0; i < min(first.size(), last.size()); i++) {
            if (first[i] != last[i]) {
                break;
            }
            ans += first[i];
        }

        return ans;
    }
};

// OR
class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        // Sort the vector of strings
        sort(arr.begin(), arr.end());

        // Compare the first and last strings in the sorted list
        string first = arr.front();
        string last = arr.back();
        int minLength = min(first.size(), last.size());

        int i = 0;
        // Find the common prefix between the first and last strings
        while (i < minLength && first[i] == last[i]) {
            i++;
        }

        // Return the common prefix
        return first.substr(0, i);
    }
};

//Approach 2: Character-by-Character Matching

class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        string ans = "";

        // Take first string as reference
        string first = arr[0];

        // Check every character of first string
        for (int i = 0; i < first.size(); i++) {
            char ch = first[i];

            // Check this character in every other string
            for (int j = 1; j < arr.size(); j++) {

                // If index is out of range OR characters are different
                if (i >= arr[j].size() || arr[j][i] != ch) {
                    return ans;
                }
            }

            // Character is common
            ans += ch;
        }

        return ans;
    }
};

//Approach 3: Divide and Conquer

class Solution {
public:
    string commonPrefix(string a, string b) {
        int i = 0;

        while (i < a.size() && i < b.size() && a[i] == b[i]) {
            i++;
        }

        return a.substr(0, i);
    }

    string divide(vector<string>& arr, int left, int right) {
        // Only one string
        if (left == right) {
            return arr[left];
        }

        int mid = left + (right - left) / 2;

        // Find LCP of left half
        string leftPrefix = divide(arr, left, mid);

        // Find LCP of right half
        string rightPrefix = divide(arr, mid + 1, right);

        // Find common prefix of both results
        return commonPrefix(leftPrefix, rightPrefix);
    }

    string longestCommonPrefix(vector<string>& arr) {
        if (arr.empty()) {
            return "";
        }

        return divide(arr, 0, arr.size() - 1);
    }
};