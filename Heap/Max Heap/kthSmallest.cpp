//Using Max-Heap (priority queue)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<int> &arr, int k) {
        // Max Heap
        priority_queue<int> pq;
        
        for(int i = 0; i < arr.size(); i++) {
            pq.push(arr[i]);
            
            // Heap mein sirf k elements rakho
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        // Top = kth smallest
        return pq.top();
    }
};

// Main Logic:-
// Hume k smallest elements maintain karne hain. Isliye Max Heap of size k banayenge.
// Why Max Heap?
// - Heap mein jo sabse bada element hoga, woh top par rahega.
// - Agar heap ka size k se bada ho gaya, toh top wale sabse bade element ko remove kar denge.
// - End mein heap mein exactly k smallest elements bachenge.
// - Unmein sabse bada = kth smallest.