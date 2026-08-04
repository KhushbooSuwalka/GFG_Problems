//Given an array arr[] containing only non-negative integers, your task is to find a continuous subarray (a contiguous sequence of elements) whose sum equals a specified value target. You need to return the 1-based indices of the leftmost and rightmost elements of this subarray. You need to find the first subarray whose sum is equal to the target.
// Note: If no such array is possible then, return [-1].

#include<bits/stdc++.h>
using namespace std;

//Approach 1 :- Using Sliding Window Technique
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int s=0,e=0;
        int n=arr.size();
        
        vector<int> res;
        int curr =0;
        
        for(int i=0;i<n;i++){
            curr += arr[i];
            
            if(curr >= target){
                e=i;
                
                while(curr>target && s<e){
                    curr -= arr[s];
                    s++;
                }
                
                if(curr == target){
                    res.push_back(s+1);
                    res.push_back(e+1);
                    return res;
                }
            }
        }
        
        return {-1};
    }
};