//Given an array, arr[]. Sort the array using bubble sort algorithm.

//Adaptive ,inplace and Stable Bubble Sort Algorithm 

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
        int n=arr.size();
        
        //Adaptive sorting
        
        for(int i=0;i<n-1;i++){
            bool swapped =false;
            
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    swapped =true;
                }
            }
            
            if(!swapped){
                break;
            }
        }
        
    }
};