//Operations to make palindromic subarray
//You are given an integer array arr[]. Your task is to consider every subarray of arr[] individually and determine the minimum number of operations required to convert each subarray into a palindromic sequence.
// In one operation, you can change any one element of the subarray to any integer.
// Operations are local to the subarray and do not affect the original array or any other subarrays.
// Each subarray is treated independently.
// A palindromic sequence is one that reads the same forwards and backwards (e.g., [1, 2, 2, 1], [7]).
// Note: Each number in the array appears at most 100 times.

//Input : arr[] = [1, 2, 2]
// Output : 2
// Explanation : Operations required for each subarray are :
// For subarray [1] : 0 operation is required.
// For subarray [2] : 0 operation is required.
// For subarray [2] : 0 operation is required.
// For subarray [1, 2] : 1 operation is required.
// For subarray [2, 2] : 0 operation is required.
// For subarray [1, 2, 2]: 1 operation is required.
// Total number of minimum operations required independentally to make all subarrays palindromic is (0 + 0 + 0 + 1 + 0 + 1) = 2. 

//Constraints:
// 1 ≤ arr[i] ≤ 105
// 1 ≤ arr.size ≤ 105

//Expected Complexities
// Time Complexity: O(n log k)
// Auxiliary Space: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long minOperation(vector<int>& arr) {
        int n=arr.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int l=i,r=j;
                int count=0;
                while(l<r){
                    if(arr[l]!=arr[r]){
                        count++;
                    }
                    l++;
                    r--;
                }
                ans+=count;
            }
        }
        return ans;
    } 
};

//Approach 2 :- 

class Solution {
public:
    long long minOperation(vector<int>& arr) {
        int n = arr.size();

        // Store positions of every value
        unordered_map<int, vector<int>> pos;

        for (int i = 0; i < n; i++) {
            pos[arr[i]].push_back(i);
        }

        long long ans = 0;

        // -----------------------------------------
        // Step 1: Count contribution of ALL pairs
        // -----------------------------------------

        for (int i = 0; i < n; i++) {

            int limit = n - 1 - i;

            //-------------
            // CASE 1:-
            //-------------
            // j <= limit
            //
            // For these pairs:
            // ways = i + 1
            //
            // j = i+1 ... limit

            if (limit > i) {
                long long count = limit - i;
                ans += count * (i + 1LL);
            }
            
            //-------------
            // CASE 2:-
            //-------------
            // j > limit
            //
            // For these pairs:
            // ways = n-j

            int start = max(i + 1, limit + 1);

            if (start < n) {
                long long count = n - start;    // (n-start) + (n-start-1) + ... + 1
                ans += count * (count + 1) / 2;
            }
        }

        // -----------------------------------------
        // Step 2: Remove equal-value pairs
        // -----------------------------------------

        for (auto &it : pos) {

            vector<int>& v = it.second;
            int m = v.size();

            // Prefix sum of positions
            vector<long long> prefix(m + 1, 0);

            for (int i = 0; i < m; i++) {
                prefix[i + 1] = prefix[i] + v[i];
            }

            for (int x = 0; x < m; x++) {

                int i = v[x];
                int limit = n - 1 - i;

                // Find first position > limit
                int p = upper_bound(v.begin() + x + 1 , v.end() , limit) - v.begin();

                // --------------------------------
                // j <= limit
                // ways = i + 1
                // --------------------------------

                long long count1 = p - (x + 1);
                ans -= count1 * (i + 1LL);

                // --------------------------------
                // j > limit
                // ways = n-j
                // --------------------------------

                long long count2 = m - p;

                if (count2 > 0) {

                    // Sum of positions v[p ... m-1]
                    long long sum = prefix[m] - prefix[p];

                    // Sum(n-j)
                    ans -= count2 * n - sum;
                }
            }
        }

        return ans;
    }
};