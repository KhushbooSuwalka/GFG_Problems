//Given an array of integers arr[], the task is to find the first equilibrium point in the array.
// The equilibrium point in an array is an index (0-based indexing) such that the sum of all elements before that index is the same as the sum of elements after it. Return -1 if no such point exists. 

#include<bits/stdc++.h>
using namespace std;

//Approach 1 :- Prefix Sum And Suffix Sum 

class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        int n = arr.size();
        vector<int> forward(n),backward(n);
        
        forward[0]=arr[0];
        backward[n-1]=arr[n-1];
        
        for (int i=1;i<n;i++){
            forward[i] = forward[i-1] + arr[i];
        }
        
        for (int i=n-2;i>=0;i--){
            backward[i] = backward[i+1] + arr[i];
        }
        
        for (int i=0;i<n;i++){
            if (forward[i]==backward[i]){
                return i;
            }
        }
        
        return -1;
    }
};

//Approach 2:- Nested Loop

int findEquilibrium(vector<int>& arr) {
    // Check for indexes one by one until an equilibrium index is found 
    for (int i = 0; i < arr.size(); ++i) {
      
      	// Get left sum 
        int leftSum = 0;
        for (int j = 0; j < i; j++)
            leftSum += arr[j];

        // Get right sum 
        int rightSum = 0;
        for (int j = i + 1; j < arr.size(); j++)
            rightSum += arr[j];

        // Check the condition
        if (leftSum == rightSum)
            return i;
    }
    
    return -1;
}