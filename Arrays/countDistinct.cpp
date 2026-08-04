//Count Distinct Elements in Every Window
//Given an integer array arr[] and a number k. Find the count of distinct elements in every window of size k in the array.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> count;
        unordered_map<int,int> freq;
        
        for (int i=0;i<k;i++){
           freq[arr[i]]++;
        }
        count.push_back(freq.size());
        
        for(int i=k;i<n;i++){
            freq[arr[i-k]]--;
            if(freq[arr[i-k]]==0){
                freq.erase(arr[i-k]);
            }
            freq[arr[i]]++;
            
            count.push_back(freq.size());
        }
        
        return count;
    }
};   