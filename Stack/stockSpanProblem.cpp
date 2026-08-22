// The stock span problem is a financial problem where we have a series of daily price quotes for a stock and we need to calculate the span of stock price for all days.
// Given an array arr[] representing daily stock prices, the stock span for the i-th day is the number of consecutive days up to day i (including day i itself) for which the price of the stock is less than or equal to the price on day i. Return the span of stock prices for each day in the given sequence.

// Examples:
// Input: arr[] = [100, 80, 90, 120]
// Output: [1, 1, 2, 4]
// Explanation: Consider each day one by one:
// Day 1 (100): Span = 1.
// Day 2 (80): Span = 1 because the previous price (100) is greater than 80.
// Day 3 (90): Span = 2 because 80 ≤ 90, but 100 > 90.
// Day 4 (120): Span = 4 because 100, 80, and 90 are all less than or equal to 120.
// Hence, the output is [1, 1, 2, 4].

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
          
        vector<int> pse(n,-1); //stores previous greater index
        vector<int> span(n);
        
        for(int i = 0 ;i<n;i++){
            while(!st.empty() && arr[i]>=arr[st.top()]){
                st.pop();
            }
            pse[i] = st.empty()?-1:st.top();
            st.push(i);

        }

        for(int j = 0 ;j<n;j++){
            span[j] = j-pse[j];
        }

        return span;
    }
};