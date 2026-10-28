//Given an array arr[] of size n, filled with numbers from 1 to n-1 in random order. The array has only one repetitive element. Return the repetitive element.
// Note: It is guaranteed that there is a repeating element present in the array.

// Examples:
// Input: arr[] = [1, 3, 2, 3, 4]
// Output: 3 
// Explanation: The number 3 is the only repeating element.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<=n;i++){
            if(arr[i]==arr[i+1]){
                return arr[i];
            }
        }
        
    }
};