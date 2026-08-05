//Given an array arr[]. The task is to find the largest element and return it.

#include <bits/stdc++.h>
using namespace std;

int largestInArray(vector<int> arr) {
    int n = arr.size();
    int largest = arr[0];
    
    for(int i=1; i<n; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
        }
    }
    
    return largest;
}

//Aproach 2:- Two pointer approach --> Submitted

class Solution {
  public:
    int largest(vector<int> &arr) {
        int i=0;
        int j=arr.size()-1;
        int maxEl=0;
        
        while(i<=j){
            if(arr[i]<arr[j]){
                maxEl = max(maxEl,arr[j]);
            }else{
                maxEl = max(maxEl,arr[i]);
            }
            i++;
            j--;
        }
        
        return maxEl;
    }
};