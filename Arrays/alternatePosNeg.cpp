//Alternate positive and negative
//Given an unsorted array arr containing both positive and negative numbers. Your task is to rearrange the array and convert it into an array of alternate positive and negative numbers without changing the relative order.
//Note:
//1. Resulting array should start with a positive integer (0 will also be considered as a positive integer).
//2. If any of the positive or negative integers are exhausted, then add the remaining integers in the answer as it is by maintaining the relative order.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void rearrange(vector<int> &arr) {
        vector<int> pos;
        vector<int> neg;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=0){
                pos.push_back(arr[i]);
            }else{
                neg.push_back(arr[i]);
            }
        }
        
        int posIndex=0,negIndex=0,i=0;
        
        while(posIndex < pos.size() && negIndex < neg.size()){
            if (i % 2 == 0)
                arr[i++] = pos[posIndex++];
            else 
                arr[i++] = neg[negIndex++];
        }
        
        while(posIndex<pos.size()){
            arr[i++]=pos[posIndex++];
        }
        
        while(negIndex<neg.size()){
            arr[i++]=neg[negIndex++];
        }
        
    }
};