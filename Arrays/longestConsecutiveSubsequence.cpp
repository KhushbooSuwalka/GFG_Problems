//Longest Consecutive Subsequence
//Given an array arr[] of non-negative integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

#include<bits/stdc++.h>
using namespace std;

//Approach 1: Sorting
class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();

        if (n == 0)
            return 0;

        sort(arr.begin(), arr.end());

        int ans = 1;
        int count = 1;

        for (int i = 1; i < n; i++) {

            // If current element is consecutive
            if (arr[i] == arr[i - 1] + 1) {
                count++;
            }

            // If duplicate, ignore it
            else if (arr[i] == arr[i - 1]) {
                continue;
            }

            // Sequence breaks
            else {
                count = 1;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};

//Approach 2: Using Hashing

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> st;

        // Insert all elements into set
        for (int x : arr) {
            st.insert(x);
        }

        int ans = 0;

        // Check every element
        for (int x : st) {

            // x is the starting point
            if (st.find(x - 1) == st.end()) { // jab find krne se wo value nhi milti ,to unordered_set st.end() return krta hai
                                              // Yaha pe agar x-1 present nhi hai to iska matlab x starting point hai
                int current = x;
                int count = 1;

                // Find consecutive numbers
                while (st.find(current + 1) != st.end()) {
                    current++;
                    count++;
                }

                ans = max(ans, count);
            }
        }

        return ans;
    }
};