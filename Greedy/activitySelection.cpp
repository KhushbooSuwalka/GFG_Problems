//Given two arrays start[] and finish[], where start[i] and finish[i] represent the start time and finish time of the i-th activity, find the maximum number of activities that a single person can perform.
// A person can perform only one activity at a time, and no two selected activities can overlap. If an activity finishes at time x, the next selected activity must start at a time greater than x.

// Examples:
// Input: start[] = [1, 3, 0, 5, 8, 5], finish[] = [2, 4, 6, 7, 9, 9]
// Output: 4
// Explanation: One possible selection is activities {0, 1, 3, 4} with time intervals (1, 2), (3, 4), (5, 7), and (8, 9). Each activity starts after the previous one finishes, so a total of 4 activities can be performed.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        vector<pair<int,int>> acts;
        int n=start.size();
        for(int i=0;i<n;i++){
            acts.push_back({finish[i],start[i]});
        }
        sort(acts.begin(),acts.end());
        
        int count=0;
        int lastFinish=-1;
        
        for(auto a:acts){
            int finishTime = a.first;
            int startTime = a.second;
            
            //select activity only if it does not overlap with last one 
            if(startTime>lastFinish){
                count++;
                lastFinish = finishTime;
            }
        }
         
        return count;
    }
};