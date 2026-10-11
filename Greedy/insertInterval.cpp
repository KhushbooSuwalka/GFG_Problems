//Geek has an array of non-overlapping intervals intervals[][] where intervals[i] = [starti , endi] represent the start and the end of the ith event and intervals is sorted in ascending order by starti . He wants to add a new interval newInterval[] = [newStart, newEnd] where newStart and newEnd represent the start and end of this interval.
// Help Geek to insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

// Examples:
// Input: intervals[][] = [[1, 3], [4, 5], [6, 7], [8, 10]], newInterval[] = [5, 6]
// Output: [[1, 3], [4, 7], [8, 10]]
// Explanation: The newInterval [5, 6] overlaps with [4, 5] and [6, 7]. So, they are merged into one interval [4, 7].

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> ans;
        int i = 0;
        int n = intervals.size();
        
        // 1. Jo intervals newInterval se pehle hain
        while(i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }
        
        // 2. Overlapping intervals ko merge karo
        while(i < n && intervals[i][0] <= newInterval[1]) {
            
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            
            i++;
        }
        
        // Merged new interval
        ans.push_back(newInterval);
        
        // 3. Baaki intervals
        while(i < n) {
            ans.push_back(intervals[i]);
            i++;
        }
        
        return ans;
    }
};