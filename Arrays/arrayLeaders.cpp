//You are given an array arr of positive integers. Your task is to find all the leaders in the array. An element is considered a leader if it is greater than or equal to all elements to its right. The rightmost element is always a leader.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> res;
        int n=arr.size();
        
        int Max = arr[n-1];
        res.push_back(Max);
        
        for(int i=n-2;i>=0;i--){
            if(arr[i] >= Max){
                Max = arr[i];
                res.push_back(Max);
            }
        }
        
        reverse(res.begin(),res.end());
        return res;
        
    }
};

