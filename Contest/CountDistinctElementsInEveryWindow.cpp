//Given an integer array arr[] and a number k. Find the count of distinct elements in every window of size k in the array.

// Examples:
// Input: arr[] = [1, 2, 1, 3, 4, 2, 3], k = 4
// Output: [3, 4, 4, 3]
// Explanation:
// First window is [1, 2, 1, 3], count of distinct numbers is 3.
// Second window is [2, 1, 3, 4] count of distinct numbers is 4.
// Third window is [1, 3, 4, 2] count of distinct numbers is 4.
// Fourth window is [3, 4, 2, 3] count of distinct numbers is 3.

#include <bits/stdc++.h>
using namespace std;

vector<int> countDistinct(vector<int> &arr, int k) {
    int n = arr.size();  
    vector<int> res;
    unordered_map<int, int> freq;
  
    // Store the frequency of elements of first window
    for(int i = 0; i < k; i++)
        freq[arr[i]] += 1;
  
    // Store the count of distinct element of first window
    res.push_back(freq.size());
  
    for(int i = k; i < n; i++) {
    	freq[arr[i]] += 1;
        freq[arr[i - k]] -= 1;
      
        // If the frequency of arr[i - k] becomes 0 remove 
        // it from hash map
        if(freq[arr[i - k]] == 0)
            freq.erase(arr[i - k]);
      
        res.push_back(freq.size());
    }
      
    return res;
}