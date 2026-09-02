//Given an integer n. You need to generate all the binary strings of n characters representing bits.
//Note: Return the strings in  ascending order.

//Examples:
//Input: n = 2
//Output: [00, 01, 10, 11]
//Explanation: As each position can be either 0 or 1, the total possible combinations are 4.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void solve(int n, string s, vector<string> &ans){
        if(s.size() == n){
            ans.push_back(s);
            return;
        }
        
        //Choose '0'
        s.push_back('0');
        solve(n,s,ans);
        s.pop_back();
        
        //Choose '1'
        s.push_back('1');
        solve(n,s,ans);
        s.pop_back();
    }
    
    vector<string> binstr(int n) {
        vector<string> ans;
        string s = "";
        
        solve(n,s,ans);
        return ans;
    }
};