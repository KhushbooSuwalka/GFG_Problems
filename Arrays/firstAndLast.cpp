//First and Last in Sorted
//Given a sorted array arr[] with possibly some duplicates, find the first and last occurrences of an element x in the given array.
// Note: If the number x is not found in the array then return both the indices as -1.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int firstOccurence(vector<int>& arr,int target, int l,int r){
        int idx=-1;
        while(l<=r){
            int mid =(l+r)/2;
            if(arr[mid]==target){
                idx=mid;
                r=mid-1;
            }else if(arr[mid]<target){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return idx;
    }
    
    int lastOccurence(vector<int>& arr,int target, int l,int r){
        int idx=-1;
        while(l<=r){
            int mid =(l+r)/2;
            if(arr[mid]==target){
                idx=mid;
                l=mid+1;
            }else if(arr[mid]<target){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return idx;
    }
    
    vector<int> find(vector<int>& arr, int x) {
        int n=arr.size();
        int l=0,r=n-1;
        int first = firstOccurence(arr,x,l,r);
        int last = lastOccurence(arr,x,l,r);
        return {first,last};
    }
};