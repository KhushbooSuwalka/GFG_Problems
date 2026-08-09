//Given an array arr, use selection sort to sort arr[] in increasing order.

//Non-adaptive ,inplace and Unstable Selection Sort Algorithm

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void selectionSort(vector<int> &arr) {
        int n=arr.size();
        
        for (int i=0;i<n-1;i++){
            int minIdx=i;
            
            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[minIdx]){
                    minIdx=j;
                }
            }
            
            swap(arr[i],arr[minIdx]);
        }
        
    }
};