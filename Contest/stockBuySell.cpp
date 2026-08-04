// Stock Buy and Sell – Max one Transaction Allowed
//Given an array prices[] of non-negative integers, representing the prices of the stocks on different days. The task is to find the maximum profit possible by buying and selling the stocks on different days when at most one transaction is allowed. Here one transaction means 1 buy + 1 Sell. If it is not possible to make a profit then return 0.
//Note: Stock must be bought before being sold.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();

        int minPrice = prices[0];
        int maximumProfit = 0;

        for (int i = 1; i < n; i++) {

            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }

            int difference = prices[i] - minPrice;

            if (difference > maximumProfit) {
                maximumProfit = difference;
            }
        }

        return maximumProfit;
    }
};