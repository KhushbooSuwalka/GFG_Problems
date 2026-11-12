//Given three integer arrays a[], b[] and c[] of equal size n, find a triplet (one element from each array) that minimizes the difference between its maximum and minimum elements. If there is a tie, return the triplet with the smallest sum. The final triplet must be returned in descending order.

// Examples:
// Input: a[] = [5, 2, 8] , b[] = [10, 7, 12] , c[] = [9, 14, 6]
// Output: [7, 6, 5]
// Explanation: The triplet [5, 7, 6]  has difference (maximum - minimum)= (7 - 5) = 2 which is minimum of all triplets.  

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());

        int i = 0, j = 0, k = 0;
        long long minDiff = LLONG_MAX;
        long long minSum = LLONG_MAX;
        vector<int> ans;

        while (i < a.size() && j < b.size() && k < c.size()) {
            int mini = min({a[i], b[j], c[k]});
            int maxi = max({a[i], b[j], c[k]});

            long long diff = maxi - mini;
            long long sum = (long long)a[i] + b[j] + c[k];

            // Check smaller difference or smaller sum
            if (diff < minDiff || (diff == minDiff && sum < minSum)) {
                minDiff = diff;
                minSum = sum;

                // Store in descending order
                ans = {maxi, a[i] + b[j] + c[k] - maxi - mini, mini};
            }

            // Move the pointer of minimum element
            if (a[i] == mini) {
                i++;
            } else if (b[j] == mini) {
                j++;
            } else {
                k++;
            }
        }

        return ans;
    }
};
