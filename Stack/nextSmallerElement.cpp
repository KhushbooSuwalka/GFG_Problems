//You are given an integer array arr[ ]. For every element in the array, your task is to determine its Next Smaller Element (NSE).
// 1. The Next Smaller Element (NSE) of an element x is the first element that appears to the right of x in the array and is strictly smaller than x.
// 2. If no such element exists, assign -1 as the NSE for that position.

// Examples:
// Input: arr[] = [4, 8, 5, 2, 25]
// Output: [2, 5, 2, -1, -1]
// Explanation: 
// The first element smaller than 4 having index > 0 is 2.
// The first element smaller than 8 having index > 1 is 5.
// The first element smaller than 5 having index > 2 is 2.
// There are no elements smaller than 4 having index > 3.
// There are no elements smaller than 4 having index > 4.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n=arr.size();
        stack<int> st;
        vector<int> res(n,-1);
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()>=arr[i]){
                st.pop();
            }
            
            if(!st.empty()){
                res[i]=st.top();
            }
            
            st.push(arr[i]);
        }
        
        return res;
    }
};