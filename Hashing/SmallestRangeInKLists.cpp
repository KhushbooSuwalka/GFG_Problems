// Given a 2d integer array mat[][] of size n*k, where each row is sorted in ascending order. Your task is to find the smallest range [l, r] that includes at least one element from each of the n lists. If more than one such ranges are found, return the first one.
// Note: If there are two possible ranges [a, b] and [c, d] with the same size, choose the one with the smaller starting value, i.e., consider [a, b] if a < c.

// Examples:
// Input: mat[][] = [[4, 7, 9, 12, 15], 
//                [0, 8, 10, 14, 20], 
//                [6, 12, 16, 30, 50]]
// Output: [6, 8]
// Explanation: Smallest range is formed by number 7 from the first list, 8 from second list and 6 from the third list.

#include <bits/stdc++.h>
using namespace std;

//Approach 1 :- using hash map

class Solution {
public:
    vector<int> findSmallestRange(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<pair<int, int>> v;   // {value, row}

        // Store every element with its row number
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                v.push_back({mat[i][j], i});
            }
        }

        // Sort according to value
        sort(v.begin(), v.end());

        unordered_map<int, int> mp;

        int count = 0;  //Current window mein kitni different rows present hain?
        int left = 0;

        int bestL = v[0].first;
        int bestR = v.back().first;

        while (left < v.size()) {
            int right = left;

            // Expand right until all rows are present
            while (right < v.size() && count < n) {
                int row = v[right].second;

                if (mp[row] == 0)
                    count++;

                mp[row]++;
                right++;
            }

            // All rows are present
            if (count == n) {
                int L = v[left].first;
                int R = v[right - 1].first;

                if (R - L < bestR - bestL) {
                    bestL = L;
                    bestR = R;
                }
            }

            // Remove left element
            int row = v[left].second;
            mp[row]--;

            if (mp[row] == 0)
                count--;

            left++;
        }

        return {bestL, bestR};
    }
};

// OR Maybe

class Solution {
public:
    vector<int> findSmallestRange(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<pair<int, int>> v;

        // Step 1: Store {value, row}
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                v.push_back({mat[i][j], i});
            }
        }

        // Step 2: Sort according to value
        sort(v.begin(), v.end());

        // mp[row] = current window mein row ke elements
        unordered_map<int, int> mp;

        int count = 0;
        int left = 0;

        int bestL = v[0].first;
        int bestR = v.back().first;

        int right = 0;

        while (right < v.size()) {
            int row = v[right].second;

            // Agar row pehli baar aa rahi hai
            if (mp[row] == 0)
                count++;

            mp[row]++;

            // Jab saari rows mil gayi
            while (count == n) {
                int L = v[left].first;
                int R = v[right].first;

                // Smaller range mila
                if (R - L < bestR - bestL) {
                    bestL = L;
                    bestR = R;
                }

                // Left element remove karo
                int leftRow = v[left].second;
                mp[leftRow]--;

                // Agar row completely remove ho gayi
                if (mp[leftRow] == 0)
                    count--;

                left++;
            }

            right++;
        }

        return {bestL, bestR};
    }
};

// Basic Logic :-
// SORTED ELEMENTS
//       ↓
// SLIDING WINDOW
//       ↓
// HASH MAP → har row ki frequency
//       ↓
// count == n ?
//       ↓
// YES → range check karo
//       ↓
// left ko move karo
//       ↓
// smallest valid range


//Approach 2 :- using multiset

class Solution {
public:
    vector<int> findSmallestRange(vector<vector<int>>& mat) {
        int n = mat.size();

        // {value, row, column}
        multiset<tuple<int, int, int>> s;

        // Har row ka first element insert karo
        for (int i = 0; i < n; i++) {
            s.insert({mat[i][0], i, 0});
        }

        int bestL = get<0>(*s.begin());
        int bestR = get<0>(*s.rbegin());

        while (true) {

            // Current minimum
            auto it = s.begin();

            int minValue = get<0>(*it);
            int row = get<1>(*it);
            int col = get<2>(*it);

            // Current maximum
            int maxValue = get<0>(*s.rbegin());

            // Current range check karo
            if (maxValue - minValue < bestR - bestL) {
                bestL = minValue;
                bestR = maxValue;
            }

            // Minimum element remove karo
            s.erase(it);

            // Agar us row mein next element hai
            if (col + 1 < mat[row].size()) {
                s.insert({
                    mat[row][col + 1],
                    row,
                    col + 1
                });

            }
            else {
                // Is row ke elements khatam ho gaye
                break;
            }
        }

        return {bestL, bestR};
    }
};