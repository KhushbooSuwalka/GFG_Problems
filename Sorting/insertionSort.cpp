//Given an array arr[] of positive integers.The task is to complete the insertsort() function which is used to implement Insertion Sort.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        int n=arr.size();
        
        for(int i=1;i<n;i++){
            int key=arr[i];
            int j=i-1;
            
            while(j>=0 && arr[j]>key){
                arr[j+1]=arr[j];
                j=j-1;
            }
            
            arr[j+1]=key;
        }
        
    }
};