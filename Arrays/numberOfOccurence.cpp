//Given a sorted array arr[] and a number target, find the number of occurrences of target in given array. 

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int i=0;
        int j=arr.size()-1;
        int count=0;
        
        while(i<j){
            if(arr[i]==target){
                count++;
            }
            if(arr[j]==target){
                count++;
            }
            i++;
            j--;
        }
        
        if(i==j && arr[i]==target){
            count++;
        }
        
        return count;
        
    }
};

//Approach 2:- Using Upper and Lower Bound By finding first and last occurence of target in the array and then calculating the number of occurrences by subtracting the indices of first and last occurrence.

class Solution {
  public:
    int firstOccurence(vector<int>& arr, int target) {
        int n=arr.size();
        int low=0,high=n-1;
        int ans=-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target){
                ans=mid;
                high=mid-1;
            }
            else if(arr[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        
        return ans;
    }

    int lastOccurence(vector<int>& arr,int target){
        int n=arr.size();
        int low=0,high=n-1;
        int ans=-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target){
                ans=mid;
                low=mid+1;
            }
            else if(arr[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        
        return ans;
    }

    int countFreq(vector<int>& arr, int target) {
        int n=arr.size();
        
        int first = firstOccurence(arr, target);
        int last = lastOccurence(arr, target);
        
        if(first==-1 || last==-1){
            return 0;
        }
        
        return last-first+1;
    }
};