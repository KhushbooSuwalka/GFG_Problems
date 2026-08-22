//Example:-
// Input: s = "*-A/BC-/AKL"
// Output: "ABC/-AK/L-*"
// Explanation:
// Prefix to infix: *-A/BC-/AKL becomes (A - (B / C)) * ((A / K) - L)
// Convert left part to Postfix: (A - (B / C)) becomes ABC/-
// Convert right part to Postfix: ((A / K) - L) becomes AK/L-
// Combine both with * to get ABC/-AK/L-*

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string preToPost(string &s) {
        stack<string> st;
        
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
                
                string temp = left + right + string(1,ch);
                st.push(temp);
            }
        }
        
        return st.top();
    }
};