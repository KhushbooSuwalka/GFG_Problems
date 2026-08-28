//Given a string s consisting only of opening and closing parentheses '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
// Note: The length of the smallest valid substring "()" is 2.

// Examples:
// Input: s = "(()("
// Output: 2
// Explanation: The longest valid substring is "()". Its length is 2. 

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxLength(string& s) {
        stack<int> st;
        st.push(-1);

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                st.push(i);
            }
            else {
                st.pop();

                if (st.empty()) {
                    st.push(i);
                }
                else {
                    ans = max(ans, i - st.top());
                }
            }
        }

        return ans;
    }
};