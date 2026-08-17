//Given a string s, composed of different combinations of '(' , ')', '{', '}', '[', ']'. Determine whether the Expression is balanced or not.
// An expression is balanced if:
// Each opening bracket has a corresponding closing bracket of the same type.
// Opening brackets must be closed in the correct order.

// Examples :
// Input: s = "[{()}]"
// Output: true
// Explanation: All the brackets are well-formed.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isBalanced(string& s) {
        stack<char> st;
        
        for(char c : s){
            if(c=='(' || c=='{' || c=='['){
                st.push(c);
            }
            else if(c==')' || c=='}' || c==']'){
                // No opening bracket
                if(st.empty()){
                    return false;
                }
                
                char top = st.top();
                if(c==')' && top!='(' || c=='}' && top!='{' || c==']' && top!='['){
                    return false;
                }
                
                // Pop matching opening bracket
                st.pop();
            }
        }
        
        // Balanced if stack is empty
        return st.empty();
    }
};