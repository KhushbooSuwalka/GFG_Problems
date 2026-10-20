//Given an array coins[], where each element represents a coin of a different denomination, and a target value sum. You have an unlimited supply of each coin type.
// Find the minimum number of coins needed to obtain the target sum. If it is not possible to form the sum using the given coins, return -1.

// Examples:
// Input: coins[] = [25, 10, 5], sum = 30
// Output: 2
// Explanation: Minimum 2 coins needed, 25 and 5  

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) { 
        vector<int> dp(sum + 1, sum + 1);
        
        // 0 sum banane ke liye 0 coins
        dp[0] = 0;
        
        for(int i = 1; i <= sum; i++) {  
            for(int coin : coins) {    
                if(coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        if(dp[sum] == sum + 1)
            return -1;
        
        return dp[sum];
    }
};