//Duplicates in a Limited Range Array
//Given an array arr[] of size n, containing elements from the range 1 to n, and each element appears at most twice, return an array of all the integers that appears twice.
// Note: You can return the elements in any order but the driver code will print them in sorted order.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int> ans;
        int i=0;
        int j=1;
        
        while(j<arr.size()){
            if(arr[i]==arr[j]){
                ans.push_back(arr[i]);
            }
            i++;
            j++;
        }
        
        return ans;
        
    }
};