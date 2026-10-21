//Given an array arr[] containing 2*n + 2 positive numbers, out of which 2*n numbers exist in pairs whereas only two number occur exactly once and are distinct. Find the other two numbers. Return the answer in increasing order.

// Examples:
// Input: arr[] = [1, 2, 3, 2, 1, 4]
// Output: [3, 4] 
// Explanation: 3 and 4 occur exactly once.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        int x=0;
        for(int num:arr){
            x=x^num;
        }
        
        int bit = x & (-x);
        int a=0,b=0;
        
        for(int num:arr){
            if(num & bit){  // If bit is not set, it belongs to the first set
                a = a^num;
            }else{
                b = b^num;  //If bit is set, it belongs to the second set
            }
        }
        
        if(a<b) return {a,b};
        else return {b,a};
    }
};