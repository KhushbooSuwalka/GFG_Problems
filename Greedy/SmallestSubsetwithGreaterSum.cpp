//You are given an array arr[] containing non-negative integers. Your task is to select the minimum number of elements such that the sum of the selected elements is greater than the sum of the remaining elements in the array.

// Examples:
// Input: arr[] = [2, 17, 7, 3]
// Output: 1
// Explanation: By selecting only the element 17, the sum of the remaining elements is 2 + 3 + 7 = 12, which is less than 17. Thus, the minimum number of elements required is 1.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minSubset(vector<int> &arr) {
        long long totalSum=0;
        for(int i=0;i<arr.size();i++){
            totalSum+=arr[i];
        }
        
        sort(arr.begin(),arr.end(),greater<int>());
        
        long long currSum=0;
        int count=0;
        
        for(int x:arr){
            currSum+=x; //add the element in currSum
            count++;
            totalSum-=x; //finding the sum of remaining elements
            if(currSum>totalSum) return count;
        }
        
        return arr.size();
    }
};