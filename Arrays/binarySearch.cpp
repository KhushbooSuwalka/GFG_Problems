//Given an array arr[], sorted in ascending order and an integer k. Return true if k is present in the array, otherwise, false.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool binarySearch(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        
        while(low<=high){
            int mid=(low+high)/2;
             
            if(arr[mid]==k){
                return true;
            }else if(arr[mid]<k){
                low=mid+1;
            }else{
                high=mid-1;
            }
             
        }
      
        return false;
    }
};