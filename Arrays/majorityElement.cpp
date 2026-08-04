//Given an array arr[]. Find the majority element in the array. If no majority element exists, return -1.
//Note: A majority element in an array is an element that appears strictly more than arr.size()/2 times in the array.

#include<bits/stdc++.h>
using namespace std;

//Approach 1:- Using Boyer-Moore's Majority Voting Algorithm

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int candidate = -1;
        int count=0;
        int n= arr.size();
        
        for(int i=0;i<n;i++){
            if(count==0){
                candidate = arr[i];
                count = 1;
            }else if(arr[i]==candidate){
                count++;
            }else{
                count--;
            }
        }
        
        count=0;
        for(int i=0;i<n;i++){
            if(arr[i]==candidate){
                count++;
            }
        }
        
        if(count > n/2){
            return candidate;
        }else{
            return -1;
        }
        
    }
};

