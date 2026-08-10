//Given an array of integers arr[]. You have to find the Inversion Count of the array. Inversion count is the number of pairs of elements (i, j) such that i < j and arr[i] > arr[j].

// Examples:
// Input: arr[] = [2, 4, 1, 3, 5]
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
// Input: arr[] = [2, 3, 4, 5, 6]
// Output: 0
// Explanation: As the sequence is already sorted so there is no inversion count.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        int count =0;
        int n=arr.size();
        
        for(int i=0;i<n-1;i++){
            int j=i+1;
            while(j<n){
                if(arr[i]>arr[j]){
                    count++;
                }
                j++;
            }
        }
       
        return count;
    }
};

//Approach 2:- By merge Sort

class Solution {
  public:
    int merge(vector<int> &arr,int low,int mid,int high){
        int count=0;
        vector<int> temp;
        
        int i=low;
        int j=mid+1;
        
        while(i<=mid && j<=high){
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i]);
                i++;
            }else{
                temp.push_back(arr[j]);
                count += mid-i+1;
                j++;
            }
        }
        
        while(i<=mid){
            temp.push_back(arr[i]);
            i++;
        }
        
        while(j<=high){
            temp.push_back(arr[j]);
            j++;
        }
        
        for(int k = low; k <= high; k++) {
            arr[k] = temp[k - low];
        }

        return count;
    }
    
    int mergeCount(vector<int> &arr,int low,int high){
        int res=0;
        
        if(low < high){
            int mid =(low+high)/2;
            res += mergeCount(arr,low,mid);
            res += mergeCount(arr,mid+1,high);
            res += merge(arr,low,mid,high);
        }
        return res;
        
    }
    
    int inversionCount(vector<int> &arr) {
        int n=arr.size();
        return mergeCount(arr,0,n-1);
    }
};