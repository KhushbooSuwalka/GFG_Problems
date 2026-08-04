//Max Sum Subarray of size K
//Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.
// Note: A subarray is a contiguous part of any given array.

#include<bits/stdc++.h>
using namespace std;

//Approach 1:- Using sliding window technique

class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n=arr.size();
        int currSum = 0;
        
        for(int i=0;i<k;i++){
            currSum += arr[i];
        }
        
        int maxSum = currSum;
        
        for(int i=k;i<n;i++){
            currSum += arr[i] - arr[i-k];
            maxSum = max(currSum,maxSum);
        }
        
        return maxSum;
        
    }
};

//Approach 2:- Nested Loop

int maximumSumSubarray(vector<int>& arr, int k)
{
    int n = arr.size();

    int maxSum = INT_MIN;

    // Traverse every possible starting index
    for(int i=0;i<=n-k;i++)
    {
        int currentSum = 0;

        // Calculate sum of k elements
        for(int j=i;j<i+k;j++)
        {
            currentSum += arr[j];
        }

        maxSum = max(maxSum,currentSum);
    }

    return maxSum;
}

//Approach 3:- Using prefix sum array

int maximumSumSubarray(vector<int>& arr, int k)
{
    int n = arr.size();
    vector<int> prefix(n);

    prefix[0]=arr[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+arr[i];
    }

    int maxSum=INT_MIN;

    for(int i=0;i<=n-k;i++){
        int currentSum;

        if(i==0)
        {
            currentSum=prefix[k-1];
        }
        else
        {
            currentSum=prefix[i+k-1]-prefix[i-1];
        }

        maxSum=max(maxSum,currentSum);
    }

    return maxSum;

}