//Given an array arr[], generate and return all possible subarrays. The subarrays must be returned in the following order:
//1. Subarrays starting from the first element, followed by subarrays starting from the second element, and so on.
//2. For each starting index, subarrays should be in increasing length.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void generateSubarrays(vector<int>& arr) {
        int n = arr.size();

        // Pick starting point
        for (int i = 0; i < n; i++) {
            // Pick ending point
            for (int j = i; j < n; j++) {
                // Print subarray from current starting point to current ending point
                for (int k = i; k <= j; k++) {
                    cout << arr[k] << " ";
                }
                cout << endl;
            }
        }
    }
};

// Approach 2:- Using Recursion

class Solution {
  public:
    void generateSubarrays(vector<int>& arr, int start, int end) {
        if (end == arr.size()) {
            return;
        } else if (start > end) {
            generateSubarrays(arr, 0, end + 1);
        } else {
            for (int i = start; i <= end; i++)  
                cout << arr[i] << " ";
            cout << endl;
            generateSubarrays(arr, start + 1, end);
        }
    }
};

// Approach 3:- Using vector to store all subarrays --> Submitted

class Solution {
  public:
    vector<vector<int>> getSubArrays(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> getSubArr;
        
        for(int i=0;i<n;i++){
            for (int j=i;j<n;j++){
                vector<int> temp;
                for(int k=i;k<=j;k++){
                    temp.push_back(arr[k]);
                }
                getSubArr.push_back(temp);
            }
        }
        
        return getSubArr;
        
    }
};
