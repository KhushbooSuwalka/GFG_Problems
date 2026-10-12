//Using Max-Heap (priority queue)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthLargest(vector<int> &arr, int k) {
        // Max Heap
        priority_queue<int> pq;
        
        // Saare elements heap mein daalo
        for(int i = 0; i < arr.size(); i++) {
            pq.push(arr[i]);
        }
        
        // k-1 largest elements remove karo
        for(int i = 1; i < k; i++) {
            pq.pop();
        }
        
        // Ab kth largest top par hai
        return pq.top();
    }
};