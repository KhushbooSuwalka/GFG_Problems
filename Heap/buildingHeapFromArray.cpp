//Given an integer array arr[], build a Max Heap from the given array.
// A Max Heap is a complete binary tree where each parent node is greater than or equal to its children, ensuring the largest element is at the root.
// Note: The driver code prints true if the resulting array represents a valid Max Heap; otherwise, it prints false. Multiple valid Max Heap arrangements are possible.

// Examples:
// Input: arr[] = [4, 10, 3, 5, 1]
// Output: true
// Explanation: The resulting array represents a valid Max Heap, with 10 as the root and every parent greater than or equal to its children.

#include<bits/stdc++.h>
using namespace std;

// Used bottom-up heapify.

class Solution {
public:
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // left child bada hai
        if (left < n && arr[left] > arr[largest])
            largest = left;

        // right child bada hai
        if (right < n && arr[right] > arr[largest])
            largest = right;

        // agar parent largest nahi hai
        if (largest != i) {
            swap(arr[i], arr[largest]);

            // jis child par value gayi hai, wahan dobara heapify
            heapify(arr, n, largest);
        }
    }

    void buildHeap(vector<int>& arr) {
        int n = arr.size();

        // Last non-leaf node se start
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
    }
};