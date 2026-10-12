//Given an integer array arr[] and an integer k, find and return the kth smallest element in the given array.

// Examples :
// Input: arr[] = [10, 5, 4, 3, 48, 6, 2, 33, 53, 10], k = 4
// Output: 5
// Explanation: 4th smallest element in the given array is 5.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<int> &arr, int k) {
        // Min Heap
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // Saare elements heap mein daalo
        for(int i = 0; i < arr.size(); i++) {
            pq.push(arr[i]);
        }
        
        // k-1 smallest elements remove karo
        for(int i = 1; i < k; i++) {
            pq.pop();
        }
        
        // Ab kth smallest top par hai
        return pq.top();
    }
};