//Example:-
// Input: s = "(a-b/c)*(a/k-l)"
// Output: *-a/bc-/akl
// Explanation: The infix expression is (a-b/c)*(a/k-l). First, inside the brackets, b/c becomes /bc and a/k becomes /ak.Now the expression looks like (a-/bc) * (/ak-l).Next, handle the subtractions: a-/bc becomes -a/bc, and /ak-l becomes -/akl. Finally, multiply the two results: (-a/bc * -/akl) becomes *-a/bc-/akl.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int precedence(char ch) {
        if (ch == '^')
            return 3;

        if (ch == '*' || ch == '/')
            return 2;

        if (ch == '+' || ch == '-')
            return 1;

        return 0;
    }

    string infixToPrefix(string s) {

        reverse(s.begin(), s.end());

        // Swap brackets
        for (char &ch : s) {
            if (ch == '(')
                ch = ')';
            else if (ch == ')')
                ch = '(';
        }

        stack<char> st;
        string ans = "";

        for (char ch : s) {

            // Operand
            if (isalnum(ch)) {
                ans += ch;
            }

            // '('
            else if (ch == '(') {
                st.push(ch);
            }

            // ')'
            else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }

                st.pop(); // remove '('
            }

            // Operator
            else {
                while (!st.empty() &&
                       st.top() != '(' &&
                       (precedence(st.top()) > precedence(ch) ||
                       (precedence(st.top()) == precedence(ch) && ch == '^'))) {

                    ans += st.top();
                    st.pop();
                }

                st.push(ch);
            }
        }

        // Remaining operators
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // Reverse postfix → prefix
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

// Approach:- Infix → Prefix
// 1. String reverse karo
// 2. '(' aur ')' swap karo
// 3. Reversed expression ko postfix mein convert karo
// 4. Postfix ko reverse karo