//Given a data stream arr[] where integers are read sequentially, find the median of the elements encountered so far after each new integer is read.
// The median is defined as follows:
// 1.Odd number of elements: The median is the middle element when the current set of numbers is sorted.
// 2. Even number of elements: The median is the arithmetic mean (average) of the two middle elements when the current set of numbers is sorted.

// Examples:
// Input: arr[] = [5, 15, 1, 3, 2, 8]
// Output: [5.0, 10.0, 5.0, 4.0, 3.0, 4.0] 
// Explanation: 
// After reading 1st element of stream – 5 -> median = 5.0
// After reading 2nd element of stream – 5, 15 -> median = (5+15)/2 = 10.0 
// After reading 3rd element of stream – 5, 15, 1 -> median = 5.0
// After reading 4th element of stream – 5, 15, 1, 3 ->  median = (3+5)/2 = 4.0
// After reading 5th element of stream – 5, 15, 1, 3, 2 -> median = 3.0
// After reading 6th element of stream – 5, 15, 1, 3, 2, 8 ->  median = (3+5)/2 = 4.0

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Using Sorting

class Solution {
public:
    vector<double> getMedian(vector<int> &arr) {
        vector<double> ans;
        vector<int> temp;
        
        for(int x : arr) {
            // New element add karo
            temp.push_back(x);
            
            // Sorted order me rakho
            sort(temp.begin(), temp.end());
            
            int n = temp.size();
            
            // Odd number of elements
            if(n % 2 == 1) {
                ans.push_back(temp[n / 2]);
            }
            
            // Even number of elements
            else {
                double median = (temp[n/2 - 1] + temp[n/2]) / 2.0;
                ans.push_back(median);
            }
        }
        
        return ans;
    }
};

// Approach 2: Using Heaps

class Solution {
public:
    vector<double> getMedian(vector<int> &arr) { 
        priority_queue<int> left;  // Max Heap
        priority_queue<int, vector<int>, greater<int>> right; // Min Heap
        
        vector<double> ans;
        
        for(int x : arr) {
            // Step 1: element ko correct heap me daalo
            if(left.empty() || x <= left.top()) {
                left.push(x);
            }
            else {
                right.push(x);
            }
            
            // Step 2: dono heaps ka size balance karo
            if(left.size() > right.size() + 1) {
                right.push(left.top());
                left.pop();
            }
            
            if(right.size() > left.size()) {
                left.push(right.top());
                right.pop();
            }
            
            // Step 3: median nikalo
            if(left.size() > right.size()) {
                ans.push_back(left.top());
            }
            else {
                double median = (left.top() + right.top()) / 2.0;
                ans.push_back(median);
            }
        }
        
        return ans;
    }
};