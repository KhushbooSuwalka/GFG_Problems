//Search in Rotated Sorted Array
//Given an array arr[] of distinct elements, which was initially sorted in ascending order but then rotated at some unknown pivot, the task is to find the index of a target key.  If the key is not present in the array, return -1.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int low=0;
        int n=arr.size();
        int high = n-1;
        
        while(low<=high){
            int mid = (low + high)/2;
            
            if(arr[mid]==key){
                return mid;
            }
            
            //If left array is sorted
            if(arr[mid]>=arr[low]){
                if(key>=arr[low] && key<arr[mid]){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }
            
            //If right array is sorted
            else{
                if(key>arr[mid] && key<=arr[high]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
            
        }
        
        return -1;
    }
};

//Approach 2 :-

class Solution{
public:
    int binarySearch(vector<int> &arr, int lo, int hi, int x) {
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] == x) return mid;
            if (arr[mid] < x) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }

    int findPivot(vector<int> &arr, int lo, int hi) {
        while (lo <= hi) {
            if (arr[lo] <= arr[hi])        
                return lo;
        
            int mid = (lo + hi) / 2;

            if (arr[mid] > arr[hi])
                lo = mid + 1;
      
            else
                hi = mid;
        }

        return lo;
    } 

    // Searches an element key in a pivoted sorted array arr of size n
    int search(vector<int> &arr, int key) {
  	    int n = arr.size();
        int pivot = findPivot(arr, 0, n - 1);

        if (arr[pivot] == key)
            return pivot;
  
        if (pivot == 0)
            return binarySearch(arr, 0, n - 1, key);

        if (arr[0] <= key)
            return binarySearch(arr, 0, pivot - 1, key);
        
        return binarySearch(arr, pivot + 1, n - 1, key);
    }

};