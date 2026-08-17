//Given a string s, repeatedly remove all adjacent duplicate character pairs until no such pairs remain.
// Return the resulting string, or "-1" if the string becomes empty.

// Examples :
// Input: s = "aaabbaaccd"
// Output: "ad"
// Explanation: 
// Remove the adjacent pairs "aa", "bb" and "cc" from "aaabbaaccd" => "ad"  
// Therefore, the final resulting string is "ad".

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string removePair(string &s) {
        stack<char> st;
        for(char c : s){
            if(!st.empty() && st.top() == c){
                st.pop();
            }else{
                st.push(c);
            }
        }
        
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        
        reverse(res.begin(),res.end());
        return res.empty() ? "-1" : res;
    }
};