//Given an array arr[], with starting index low and ending index high, complete the functions partition() and quickSort() so that the array becomes sorted in ascending order.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        if(low<high){
            int p=partition(arr,low,high);
            quickSort(arr,low,p-1);
            quickSort(arr,p+1,high);
        }
    }

    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i=low-1;
        
        for(int j=low;j<high;j++){
            if(arr[j]<=pivot){
                i++;
                swap(arr[i],arr[j]);
            }
        }
        
        swap(arr[i+1],arr[high]);
        return i+1;
        
    }
};