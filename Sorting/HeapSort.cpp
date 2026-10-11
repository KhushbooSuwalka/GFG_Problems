//Examples:
// Input: arr[] = [4, 1, 3, 9, 7]
// Output: [1, 3, 4, 7, 9]
// Explanation: After sorting elements using heap sort, elements will be in order as 1, 3, 4, 7, 9.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i; // Initialize largest as root
        int left = 2 * i + 1; // left child index
        int right = 2 * i + 2; // right child index

        // If left child is larger than root
        if (left < n && arr[left] > arr[largest])
            largest = left;

        // If right child is larger than largest so far
        if (right < n && arr[right] > arr[largest])
            largest = right;

        // If largest is not root
        if (largest != i) {
            swap(arr[i], arr[largest]); // Swap root with largest

            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }

    void heapSort(vector<int>& arr) {
        int n = arr.size();

        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        // One by one extract elements from heap
        for (int i = n - 1; i >= 0; i--) {
            swap(arr[0], arr[i]); // Move current root to end

            // Call max heapify on the reduced heap
            heapify(arr, i, 0);
        }
    }

};