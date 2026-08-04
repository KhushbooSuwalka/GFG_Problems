//Majority Element - More Than n/3
//Given an array arr[] consisting of n integers, find all the array elements which occurs more than floor(n/3) times. Return the resulting array in strictly increasing order. If no such elements exist, return an empty array.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        int n=arr.size();
        int candidate1=-1,candidate2=-1;
        int count1=0,count2=0;
        
        for(int i=0;i<n;i++){
            if(arr[i]==candidate1){
                count1++;
            }else if(arr[i]==candidate2){
                count2++;
            }else if(count1==0){
                candidate1=arr[i];
                count1 =1;
            }else if(count2==0){
                candidate2=arr[i];
                count2 = 1;
            }else{
               count1--;
               count2--;
            }
            
        }
        
        vector<int> res;
        count1=0,count2=0;
        
        for(int i=0;i<n;i++){
            if(arr[i]==candidate1){
                count1++;
            }else if(arr[i]==candidate2){
                count2++;
            }
        }
        
        if(count1>n/3){
            res.push_back(candidate1);
        }
        if(candidate1 != candidate2 && count2 > n/3){
            res.push_back(candidate2);
        }
        
        sort(res.begin(), res.end());
        return res;
        
    }
};
