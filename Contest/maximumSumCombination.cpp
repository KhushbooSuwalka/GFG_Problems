//You are given two integer arrays a[] and b[] of equal size. A sum combination is formed by adding one element from a[] and one from b[], using each index pair (i, j) at most once. Return the top k maximum sum combinations, sorted in non-increasing order.

// Examples:
// Input: a[] = [3, 2], b[] = [1, 4], k = 2
// Output: [7, 6]
// Explanation: Possible sums: 3 + 1 = 4, 3 + 4 = 7, 2 + 1 = 3, 2 + 4 = 6, Top 2 sums are 7 and 6.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();

        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());

        priority_queue<pair<int, pair<int,int>>> pq;

        for(int i = 0; i < n; i++) {
            pq.push({a[i] + b[0], {i, 0}});
        }

        vector<int> ans;

        while(k--) {
            
            auto t = pq.top();
            pq.pop();

            int sum = t.first;
            int i = t.second.first;
            int j = t.second.second;

            ans.push_back(sum);

            if(j + 1 < n) {
                pq.push({a[i] + b[j + 1], {i, j + 1}});
            }
        }

        return ans;
    }
};