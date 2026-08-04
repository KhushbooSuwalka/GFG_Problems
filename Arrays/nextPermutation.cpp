//Given an array of integers arr[] representing a permutation, implement the next permutation that rearranges the numbers into the lexicographically next greater permutation. If no such permutation exists, rearrange the numbers into the lowest possible order (i.e., sorted in ascending order).

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        int n=arr.size();
        int pivot=n-2;
        
        //Find the pivot
        while(pivot>=0 && arr[pivot]>=arr[pivot+1]){
            pivot--;
        }
        
        //Find succesor
        if(pivot>=0){
            int succesor=n-1;
            
            while(arr[succesor]<=arr[pivot]){
                succesor--;
            }
            
            //Swap the pivot and the succesor
            swap(arr[pivot],arr[succesor]);
        }
        
        reverse(arr.begin() + pivot +1,arr.end());
    }
};