// Trapping Rain Water
// Given an array arr[] with non-negative integers representing the height of blocks. If the width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 

#include<bits/stdc++.h>
using namespace std;

//Approach 1: Using Two Pointers

int maxWater(vector<int> &arr) { 
    int left = 0;
    int right = arr.size() - 1;

    int leftMax = 0;
    int rightMax = 0;

    int water = 0;
    while (left <= right) {
      if (arr[left] <= arr[right]) {
        if (arr[left] >= leftMax) {
          leftMax = arr[left];
        } else {
          water += leftMax - arr[left];
        }
        left++;
      } else {
        if (arr[right] >= rightMax) {
          rightMax = arr[right];
        } else {
          water += rightMax - arr[right];
        }
        right--;
      }
    }
        
    return water ;
}

//Approach 2: Brute Force Approach

class Solution {
public:
    int maxWater(vector<int>& arr) {
        int n = arr.size();
        int water = 0;

        for (int i = 0; i < n; i++) {

            int leftMax = arr[i];
            for (int j = 0; j < i; j++) {
                leftMax = max(leftMax, arr[j]);
            }

            int rightMax = arr[i];
            for (int j = i + 1; j < n; j++) {
                rightMax = max(rightMax, arr[j]);
            }

            water += min(leftMax, rightMax) - arr[i];
        }

        return water;
    }
};

//Approach 3: Using Prefix and Suffix Arrays

class Solution {
public:
    int maxWater(vector<int>& arr) {

        int n = arr.size();

        vector<int> leftMax(n);
        vector<int> rightMax(n);

        leftMax[0] = arr[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], arr[i]);
        }

        rightMax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], arr[i]);
        }

        int water = 0;

        for (int i = 0; i < n; i++) {
            water += min(leftMax[i], rightMax[i]) - arr[i];
        }

        return water;
    }
};