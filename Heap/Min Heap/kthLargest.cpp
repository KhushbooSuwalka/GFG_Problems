//Given an array arr[] and a number k. The task is to find the kth largest element in the array.

// Examples:
// Input: arr[] = [3, 5, 4, 2, 9], k = 3
// Output: 4
// Explanation: Third largest element in the array is 4.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthLargest(vector<int> &arr, int k) {
        // Min Heap
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < arr.size(); i++) {
            pq.push(arr[i]);
            
            // Sirf k largest elements rakho
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        // Top = kth largest
        return pq.top();
    }
};