//You are given a string s that represents the postfix form of a valid mathematical expression. Convert it to its prefix form.

// Examples :
// Input: s = "ab+"
// Output: "+ab"
// Explanation: In prefix form, operator comes before operands.
// Postfix to Infix: ab+ becomes a + b 
// Infix to Prefix: a + b becomes +ab 

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string postToPre(string s) {
        stack<string> st;
        
        for(char ch:s){
            if(isalnum(ch)){
                st.push(string(1,ch));
                // Suppose: ch = 'a';
                // string(1, ch) ka matlab: 'a' se 1 character ki string banao.
            }else{
                string right = st.top();
                st.pop();
                
                string left = st.top();
                st.pop();
                
                string temp = string(1,ch) + left + right;
                st.push(temp);
            }
        }
        
        return st.top();
    }
};