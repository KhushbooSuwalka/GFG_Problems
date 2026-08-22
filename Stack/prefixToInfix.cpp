//Given a string s representing a valid mathematical expression in prefix notation. The string consists of uppercase and lowercase English letters as operands, and the operators +, -, *, /, %, and ^.

// Examples :
// Input: s = "*-A/BC-/AKL"
// Output: ((A-(B/C))*((A/K)-L))
// Explanation: The prefix expression starts with '*', so the final operation is multiplication.
// The left subexpression '-A/BC' converts to '(A-(B/C))', and the right subexpression '-/AKL' converts to '((A/K)-L)'.
// Combining these two subexpressions with '*' gives the fully parenthesized infix expression: ((A-(B/C))*((A/K)-L))

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string preToInfix(string &s) {
        stack<string> st;
        
        // Right to left
        for(int i=s.length()-1;i>=0;i--){
            char ch = s[i];
            
            if(isalnum(ch)){
                st.push(string(1,ch));
            }
            else{
                string left = st.top();
                st.pop();
                
                string right = st.top();
                st.pop();
                
                string temp = "("+left+ch+right+")";
                st.push(temp);
            }
        }
        
        return st.top();
    }
};