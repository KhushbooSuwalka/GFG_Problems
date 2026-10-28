//Leetcode question
// There are n flights that are labeled from 1 to n.
// You are given an array of flight bookings bookings, where bookings[i] = [firsti, lasti, seatsi] represents a booking for flights firsti through lasti (inclusive) with seatsi seats reserved for each flight in the range.
// Return an array answer of length n, where answer[i] is the total number of seats reserved for flight i.

// Example 1:
// Input: bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
// Output: [10,55,45,25,25]
// Explanation:
// Flight labels:        1   2   3   4   5
// Booking 1 reserved:  10  10
// Booking 2 reserved:      20  20
// Booking 3 reserved:      25  25  25  25
// Total seats:         10  55  45  25  25
// Hence, answer = [10,55,45,25,25]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> answer(n, 0);
        for (const auto& b : bookings) {
            int first = b[0] - 1;
            int last = b[1];
            int seats = b[2];
            answer[first] += seats;
            if (last < n) {
                answer[last] -= seats;
            }
        }
        for (int i = 1; i < n; ++i) {
            answer[i] += answer[i - 1];
        }
        return answer;
    }
};