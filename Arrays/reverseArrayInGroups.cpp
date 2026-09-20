//Given an integer array arr[] and an integer k, reverse every consecutive group of k elements. If fewer than k elements remain at the end, reverse all of them.

// Examples:
// Input: arr[] = [1, 2, 3, 4, 5], k = 3
// Output: [3, 2, 1, 5, 4]
// Explanation: First group consists of elements 1, 2, 3. Second group consists of 4, 5.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void reverseInGroups(vector<int> &arr, int k) {
        int n = arr.size();
        
        for(int i=0;i<n;i+=k){
            int left = i;
            int right = min(i+k-1,n-1);
            
            while(left<right){
                swap(arr[left++],arr[right--]);
            }
        }
    }
};