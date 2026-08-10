//The Painter's Partition Problem-II
//Given an array arr[] where each element denotes the length of a board, and an integer k representing the number of painters available. Each painter takes 1 unit of time to paint 1 unit length of a board.
// Determine the minimum amount of time required to paint all the boards, under the constraint that each painter can paint only a contiguous sequence of boards (no skipping or splitting allowed).

//Examples:
// Input: arr[] = [5, 10, 30, 20, 15], k = 3
// Output: 35
// Explanation: The optimal allocation of boards among 3 painters is - 
// Painter 1 → [5, 10] → time = 15
// Painter 2 → [30] → time = 30
// Painter 3 → [20, 15] → time = 35
// Job will be done when all painters finish i.e. at time = max(15, 30, 35) = 35

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool check(vector<int>& arr,int mid,int k){
        int painter =1;
        int currentSum =0;

        for(int i=0;i<arr.size();i++){
            if(currentSum + arr[i] <= mid){
                currentSum += arr[i];
            }else{
                painter++;
                currentSum = arr[i];
            }

        }
        return painter<=k;
    }

    int minTime(vector<int>& arr, int k) {
        int n=arr.size();
        int low,high;
        int ans=-1;

        int sum=0,maxEle=arr[0];
        for(int i=0;i<n;i++){
            if(arr[i]>maxEle){
                maxEle = arr[i];
            }
            sum += arr[i];
        }
        
        low = maxEle;
        high = sum;

        while(low<=high){
            int mid=(low+high)/2;

            if(check(arr,mid,k)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return ans;
    }
};