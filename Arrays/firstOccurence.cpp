//First Occurrence In Sorted
//Given a sorted array arr[] and an integer k, find the position(0-based indexing) at which k is present in the array using binary search. If k doesn't exist in arr[] return -1. 
// Note: If multiple occurrences are there, please return the smallest index.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int firstSearch(vector<int> &arr, int k) {
        int low=0;
        int high=arr.size() -1;
        int result = -1;
        
        while (low<=high){
            int mid = (low + high)/2;
            if(arr[mid]==k){
                result = mid;
                high = mid -1;
            }else if(arr[mid]<k){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        
        return result;
    }
};