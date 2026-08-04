//Rotate Array
//Given an array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. Do the mentioned change in the array in place.
//Note: Consider the array as circular.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void rotateArr(vector<int>& arr, int d) {
        int n= arr.size();
        for (int i =0;i<d;i++){
            int first=arr[0];
            for(int j=0;j<n-1;j++){
                arr[j]=arr[j+1];
            }
            arr[n-1]=first;
        }
    }
};

//Approach 2:- Use Reversal algorithm

class Solution {
  public:
    void rotateArr(int arr[], int d, int n) {
        d = d % n; // handle cases where d > n
        reverse(arr, 0, d - 1);     // Step 1: reverse first d elements
        reverse(arr, d, n - 1);     // Step 2: reverse remaining n-d elements
        reverse(arr, 0, n - 1);     // Step 3: reverse whole array

        // Alternative using reverse function:-
        // reverse(arr.begin(), arr.begin() + d);
        // reverse(arr.begin() + d, arr.end());
        // reverse(arr.begin(), arr.end());
    }

    void reverse(int arr[], int start, int end) {
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
};

//Approach 3:-Using Temporary Array --> Submitted
   
class Solution {
  public:
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();

        d=d%n;
        vector<int> temp(n);

        for (int i = 0; i < n - d; i++)
            temp[i] = arr[d + i];
    
        for (int i = 0; i < d; i++)
            temp[n - d + i] = arr[i];
 
        for (int i = 0; i < n; i++)
            arr[i] = temp[i];
        
    }
};