//Koko is given an array arr[], where each element represents a pile of bananas. She has exactly k hours to eat all the bananas.
// Each hour, Koko can choose one pile and eat up to s bananas from it.
// 1. If the pile has atleast s bananas, she eats exactly s bananas.
// 2. If the pile has fewer than s bananas, she eats the entire pile in that hour.

// Koko can only eat from one pile per hour.
// Your task is to find the minimum value of s (bananas per hour) such that Koko can finish all the piles within k hours.

//Examples:
// Input: arr[] = [5, 10, 3], k = 4
// Output: 5
// Explanation: If Koko eats at the rate of 5 bananas per hour:
// First pile of 5 bananas will be finished in 1 hour.
// Second pile of 10 bananas will be finished in 2 hours.
// Third pile of 3 bananas will be finished in 1 hours.
// Therefore, Koko can finish all piles of bananas in 1 + 2 + 1 = 4 hours.

#include<bits/stdc++.h>
using namespace std;

int kokoEat(vector<int>& arr, int k) {
    
    int mx = *max_element(arr.begin(), arr.end());

    for (int speed = 1; speed <= mx; speed++) {
        long long reqTime = 0;

        for (int i = 0; i < arr.size(); i++) {         
            // add the time needed to eat this pile at the current speed
            reqTime += (arr[i] + speed - 1) / speed;
        }

        // if total time is within allowed hours,return this speed
        if (reqTime <= k) {
            return speed;
        }
    }
    
    // if no smaller speed works, return the max pile size
    return mx; 
}

//Approach 2 :- using binary search --> Submitted

class Solution {
  public:
    bool check(vector<int>& arr,int mid,int k){
        int totalHours =0;
        for(int j=0;j<arr.size();j++){
            totalHours += (arr[j]+mid-1)/mid;
        }
        
        return totalHours<=k ;
        
    }
    
    int kokoEat(vector<int>& arr, int k) {
        int low =1;
        int high = *max_element(arr.begin(),arr.end());
        int res=high;
        
        while(low<=high){
            int mid = (low+high)/2;
            if(check(arr,mid,k)){
                res=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        
        return res;
    }
};