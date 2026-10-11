//Given two arrays s[] and f[], where s[i] and f[i] denote the start time and finish time of the ith meeting, respectively. There is only one meeting room. A meeting can be scheduled only if its start time is strictly greater than the finish time of the previously selected meeting.
// Find the maximum number of meetings that can be scheduled in the room such that no two selected meetings overlap. Return the indices (1-based) of the selected meetings in sorted (increasing) order.
// Note: If multiple schedules are possible, prefer meetings with earlier finish times. If two meetings have the same finish time, prefer the meeting with the smaller index.

// Examples:
// Input: s[] = [1, 3, 0, 5, 8, 5], f[] = [2, 4, 6, 7, 9, 9] 
// Output: [1, 2, 4, 5]
// Explanation: We can attend the 1st meeting from (1 to 2), then the 2nd meeting from (3 to 4), then the 4th meeting from (5 to 7), and the last meeting we can attend is the 5th from (8 to 9). It can be shown that this is the maximum number of meetings we can attend.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxMeetings(vector<int>& s, vector<int>& f) {
        int n = s.size();

        // {finish time, start time, index}
        vector<pair<pair<int,int>,int>> meetings;

        for(int i = 0; i < n; i++) {
            meetings.push_back({{f[i], s[i]}, i + 1});
        }

        // Sort by finish time
        // If finish same -> smaller index
        sort(meetings.begin(), meetings.end());

        vector<int> ans;
        // First meeting
        ans.push_back(meetings[0].second);

        int lastFinish = meetings[0].first.first;

        // Check remaining meetings
        for(int i = 1; i < n; i++) {
            int startTime = meetings[i].first.second;
            int finishTime = meetings[i].first.first;

            // Start must be strictly greater than previous meeting's finish
            if(startTime > lastFinish) {
                ans.push_back(meetings[i].second);
                lastFinish = finishTime;
            }
        }

        // Indices need to be increasing
        sort(ans.begin(), ans.end());

        return ans;
    }
};