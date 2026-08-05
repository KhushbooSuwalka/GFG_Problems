//Two sum -Pairs with 0 Sum
//Given an integer array arr, return all the unique pairs [arr[i], arr[j]] such that i != j and arr[i] + arr[j] == 0.
// Note: The pairs must be returned in sorted order, the solution array should also be sorted, and the answer must not contain any duplicate pairs.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        vector<vector<int>> res;
        int n=arr.size();
        
        sort(arr.begin(),arr.end());
        int i=0,j=n-1;
        
        while(i<j){
            vector<int> temp(2);
            if(arr[i]+arr[j]==0){
                if(arr[i]>arr[j]){
                    temp[0]=arr[j];
                    temp[1]=arr[i];
                }else{
                    temp[0]=arr[i];
                    temp[1]=arr[j];
                }
                res.push_back(temp);
                while(i!=j && arr[i]==temp[0]){
                    i++;
                }
                while(i!=j && arr[i]==temp[1]){
                    j--;
                }
            }else if(arr[i]+arr[j]>0){
                j--;
            }else{
                i++;
            }
        }
        
        return res;
    }
};