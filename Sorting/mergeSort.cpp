//Given an array arr[], its starting position l and its ending position r. Sort the array using the merge sort algorithm.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void merge(vector<int>& arr, int l, int mid,int r){
        int n=arr.size();
        
        vector<int> temp(r-l+1);
        int i=l,j=mid+1,k=0;
        
        while(i<=mid && j<=r){
            if(arr[i]<=arr[j]){
                temp[k++]=arr[i++];
            }else{
                temp[k++]=arr[j++];
            }
        }
        
        while(i<=mid){
            temp[k++]=arr[i++];
        }
        
        while(j<=r){
            temp[k++]=arr[j++];
        }
        
        for(int i=l;i<=r;i++){
            arr[i]=temp[i-l];
        }
        
    }
    
    void mergeSort(vector<int>& arr, int l, int r) {
        if(l<r){
            int mid =(l+r)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
        
    }
};