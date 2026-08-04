//Move all zeroes to end of the array
//You are given an array arr[] of non-negative integers. You have to move all the zeros in the array to the right end while maintaining the relative order of the non-zero elements. The operation must be performed in place, meaning you should not use extra space for another array

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int n = arr.size();
        int j=0;
        vector<int> temp(n);
        
        for (int i=0;i<n;i++){
            if(arr[i]!=0){
                temp[j++]=arr[i];
            }
        }
        
        while(j<n){
            temp[j++]=0;
        }
        
        for(int i=0;i<n;i++){
            arr[i]=temp[i];
        }
    }
};

//Approach 2:-Two traversals

class Solution {
  public:
    void pushZerosToEnd(vector<int> &arr){
        int count = 0;
        for (int i = 0; i < arr.size(); i++){
            if (arr[i] != 0)
                arr[count++] = arr[i];
        }
       
        while (count < arr.size())
            arr[count++] = 0;
    }
};

//Approach 3:- One traversal

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int n = arr.size();
        int j=0;
        
        for (int i=0;i<n;i++){
            if(arr[i]!=0){
                swap(arr[i],arr[j]);
                j++;
            }
        }
    }
};

