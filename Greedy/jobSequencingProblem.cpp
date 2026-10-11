//You are given two arrays: deadline[], and profit[], which represent a set of jobs, where each job is associated with a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.
// Your task is to return the following two values
// 1. Number of jobs selected for the maximum profit. 
// 2. The total maximum profit by completing those jobs.

// Examples :
// Input: deadline[] = [4, 1, 1, 1], profit[] = [20, 10, 40, 30]
// Output: [2, 60]
// Explanation: Job1 and Job3 can be done with maximum profit of 60 (20 + 40).

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n=deadline.size();
        vector<pair<int,int>> jobs;
        
        for(int i=0;i<n;i++){
            jobs.push_back({profit[i],deadline[i]});
        }
        
        sort(jobs.rbegin(),jobs.rend());
        
        int maxDeadline=0;
        for(int i=0;i<n;i++)  maxDeadline = max(maxDeadline,deadline[i]);
        
        int count=0,total=0;
        vector<int> slot(maxDeadline+1,-1);
        
        for(int i = 0; i < n; i++) {
            int jobProfit = jobs[i].first;
            int jobDeadline = jobs[i].second;

            // Start from latest possible slot
            for(int j = jobDeadline; j >= 1; j--) {
                if(slot[j] == -1) {
                    // Put job here
                    slot[j] = jobProfit;

                    count++;
                    total += jobProfit;

                    break;
                }
            }
        }
        
        return {count,total};
    }
};

// Approach 2 :- 

class Solution {
  public:
    // Find latest available slot
    int find(vector<int>& parent, int x) {
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent, parent[x]);
    }
    
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n=deadline.size();
        vector<pair<int,int>> jobs;
        
        for(int i=0;i<n;i++){
            jobs.push_back({profit[i],deadline[i]});
        }
        
        sort(jobs.rbegin(),jobs.rend());
        
        // parent[i] = latest available slot <= i
        vector<int> parent(n + 1);
        for(int i=0;i<=n;i++)  parent[i] = i;
        
        int count=0,total=0;
        
        for(int i = 0; i < n; i++) {
            int jobProfit = jobs[i].first;
            int jobDeadline = jobs[i].second;

            // Find latest available slot
            int slot = find(parent, jobDeadline);

            // Slot 0 means no slot is available before this
            if(slot > 0) {
                count++;
                total += jobProfit;

                // Mark this slot as occupied
                parent[slot] = find(parent, slot - 1);
            }
        }
        
        return {count,total};
    }
};