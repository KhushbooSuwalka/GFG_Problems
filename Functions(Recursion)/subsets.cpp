//Given an array arr[] of distinct positive integers, your task is to find all its subsets.
//Note: You can return the subsets in any order, the driver code will print them in sorted order.

//Examples:
//Input: arr[] = [1, 2, 3]
//Output: [[], [1], [1, 2], [1, 2, 3], [1, 3], [2], [2, 3], [3]]

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void solve(int index, vector<int>& arr, vector<int>& current, vector<vector<int>>& ans){
        if(index == arr.size()){
            ans.push_back(current);
            return;
        }
        
        // Take
        current.push_back(arr[index]);
        solve(index+1, arr, current, ans);
        
        //Don't take
        current.pop_back();
        solve(index+1 ,arr ,current ,ans);           // Take and Don't take creates a decision tree.
    }
    
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> current;
        
        solve(0,arr,current,ans);
        
        return ans;
    }
};