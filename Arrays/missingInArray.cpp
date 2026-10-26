//You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). This array represents a permutation of the integers from 1 to n with one element missing. Your task is to identify and return the missing element.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int missingNum(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int j=1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=j){
                return j;
            }
            j++;
        }
        return j;
        
    }
};

// Approach 2 :- Optimal

class Solution {
  public:
    int missingNum(vector<int>& arr) {
        int n = arr.size() + 1;
        int xor1 = 0, xor2 = 0;

        // XOR all array elements
        for (int i = 0; i < n - 1; i++) {
            xor2 ^= arr[i];
        }

        // XOR all numbers from 1 to n
        for (int i = 1; i <= n; i++) {
            xor1 ^= i;
        }

        // Missing number is the XOR of xor1 and xor2
        return xor1 ^ xor2;
    }
};