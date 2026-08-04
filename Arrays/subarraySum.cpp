//Subarrays with given sum
//Given an unsorted array arr[] of integers and a sum k. Count the number of subarrays that add to a given number k.
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int subArraySum(vector<int>& arr, int k) {
        int n=arr.size();
        int count = 0;
        
        for(int i=0;i<n;i++){
            int curr =0;
            
            for(int j=i;j<n;j++){
                curr += arr[j];
                if(curr==k){
                    count++;
                }
            }
            
        }
        
        return count;
        
    }
};

//Approach 2 :- Using prefix sum and unordered_map

class Solution {
  public:
    int subArraySum(vector<int>& arr, int k) {
        int sum=0,count=0;
        unordered_map<int,int> prefixCount;
        
        prefixCount[0] = 1;
        
        for(int i=0 ; i<arr.size() ; i++){
            sum += arr[i];
            
            if(prefixCount.find(sum-k) != prefixCount.end()){
                count += prefixCount[sum-k];
            }
            
            prefixCount[sum]++;
        }
        
        return count;
        
    }
};