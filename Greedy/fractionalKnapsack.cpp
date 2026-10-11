//Given two arrays, val[] and wt[] , representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.
// Return the maximum value as a double, rounded to 6 decimal places.

// Examples :
// Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
// Output: 240.000000
// Explanation: By taking items of weight 10 and 20 kg and 2/3 fraction of 30 kg. Hence total price will be 60+100+(2/3)(120) = 240

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size();
        vector<pair<double,pair<int,int>>> items;
        
        for(int i=0;i<n;i++){
            double ratio = (double)val[i]/wt[i];
            items.push_back({ratio,{val[i],wt[i]}});
        }
        
        sort(items.rbegin(),items.rend());
        
        double ans=0;
        for(int i=0;i<n;i++){
            int value = items[i].second.first;
            int weight = items[i].second.second;
            if(weight<=capacity){
                ans+=(double)value;
                capacity-=weight;
            }else{
                ans+=(double)value/weight*capacity;
                break;
            }
        }
        
        return ans;
    }
};