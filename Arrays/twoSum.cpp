//Two Sum - Pair with Given Sum
//Given an array arr[] of integers and another integer target. Determine if there exist two distinct indices such that the sum of their elements is equal to the target.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[j]+arr[i]==target){
                    return true;
                }
            }
        }
        return false;
        
    }
};

//Approach 2:-Using Sorting and Binary Search

class Solution {
  public:
    bool binarySearch(vector<int> &arr, int low, int high,int target){
        while (low <= high){
            int mid = (low + high) / 2;

            if (arr[mid] == target)
                return true;
            if (arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
    
    bool twoSum(vector<int>& arr, int target) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n;i++){
            int complement=target-arr[i];
            
            if(binarySearch (arr,i+1,n-1,complement)){
                return true;
            }
        }
        
        return false;
        
    }
};

//Approach 3:-Using Sorting and Two Pointers

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        int i=0,j=n-1;
        
        while(i<j){
            int sum = arr[i]+arr[j];
            if(sum == target){
                return true;
            }else if(sum < target){
                i++;
            }else{
                j--;
            }
        }
        
        return false;
        
    }
};

//Approach 4:-Using Hashing - Unordered Map , which has key and value pair like a dictionary .

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        //An unordered_set stores unique values and allows us to quickly check whether a value exists.
        unordered_set<int> s;   //Initially the set is empty.
        for(int i=0;i<arr.size();i++){
            int complement=target-arr[i];
            if(s.find(complement)!=s.end()){
                return true;
            }
            s.insert(arr[i]);
        }
        return false;
    }
};