//Segregate 0s and 1s
//Given an array arr[] consisting of only 0's and 1's. Modify the array in-place to segregate 0s onto the left side and 1s onto the right side of the array.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void segregate0and1(vector<int>& arr) {
  
        // Count 0s
        int count = 0; 
        for (int x : arr)
            if (x == 0)
                count++;

        // Fill the vector with 0s until count
        for (int i = 0; i < count; i++)
            arr[i] = 0;

        // Fill the remaining vector space with 1s
        for (int i = count; i < arr.size(); i++)
            arr[i] = 1;

    }
};

//Approach 2:- Using Hoare's Partition Algorithm

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int i =0;
        int j =arr.size()-1;
        while(i<j){
            if(arr[i]==0 && i<j){
                i++;
            }
            if(arr[j]==1 && i<j){
                j--;
            }
            else if(arr[i]==1 && arr[j]==0){
                swap(arr[i],arr[j]);
                i++;
                j--;
            }
        }
        
    }
};
