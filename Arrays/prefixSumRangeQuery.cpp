//Given an array arr[] of integers and a list of q queries queries[][], where each query is in the form [L, R], compute the sum of elements from index L to R (both inclusive) for each query.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> rangeSumQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        
        vector<int> pSum(n);
        pSum[0] = arr[0];
        
        for(int i=1;i<n;i++){
            pSum[i] = pSum[i-1] + arr[i];
        }
        
        vector<int> ans;
        for(auto &q:queries){
            int i=q[0];
            int j=q[1];
            
            if(i==0){
                int currSum = pSum[j];
                ans.push_back(currSum);
            }else{
                int currSum = pSum[j] - pSum[i-1];
                ans.push_back(currSum);
            }
        }
        
        return ans;
    }
};