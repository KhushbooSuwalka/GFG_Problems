// Given a number n, return all the combinations of balanced parentheses of length n.
// Note: A sequence of parentheses is balanced if every opening bracket has a corresponding closing bracket in the correct order.
// For example, "(())", "()()", and "(()())" are balanced, whereas ")()(", "))((", and "()))" are not.

// Examples:
// Input: n = 6
// Output: ["((()))", "(()())", "(())()", "()(())", "()()()"]
// Explanation: These are the only possible valid balanced parentheses.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void solve(int n, int open, int close, string &s, vector<string> &ans){
        
        // Base Case
        if(open == n && close == n){
            ans.push_back(s);
            return;
        }

        //Choose '('
        if(open < n){
            s.push_back('(');
            solve(n, open+1, close, s, ans);
            s.pop_back();    // Undo 
        }

        //Choose ')'
        if(close < open){
            s.push_back(')');
            solve(n, open, close+1, s, ans);
            s.pop_back();   // Undo 
        }
    }
    
    vector<string> generateParentheses(int n) {
        vector<string> ans;
        string s = "";
        
        solve(n/2,0,0,s,ans);
        
        return ans;
        
    }
};