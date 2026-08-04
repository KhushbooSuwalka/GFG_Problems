// Sort 0s,1s and 2s in an array -> Medium level
//Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void sort012(vector<int>& arr) {
        int count0=0,count1=0,count2=0;
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                count0++;
            }else if(arr[i]==1){
                count1++;
            }else{
                count2++;
            }
        }
        
        for(int i=0;i<count0;i++){
            arr[i]=0;
        }
        for(int i=count0 ; i < count0+count1 ; i++){
            arr[i]=1;
        }
        for(int i= count0+count1;i<n;i++){
            arr[i]=2;
        }
    }
};

//Solution By DNF Algorithm  
class Solution {
   public:
    void sort012(vector<int>& arr) {
        int low=0,mid=0,high=arr.size()-1;
        
        while(mid<=high){
            if(arr[mid]==0){
                swap(arr[low],arr[mid]);
                low++;
                mid++;
            }else if(arr[mid]==1){
                mid++;
            }else{
                swap(arr[mid],arr[high]);
                high--;
            }
        }
    }
};