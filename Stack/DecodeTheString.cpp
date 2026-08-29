//Given an encoded string s, decode it by expanding the pattern k[substring], where the substring inside brackets is written k times. k is guaranteed to be a positive integer, and encodedString contains only lowercase english alphabets. Return the final decoded string.
// Note: The test cases are generated so that the length of the output string will never exceed 105 .

// Examples:
// Input: s = "3[b2[ca]]"
// Output: "bcacabcacabcaca"
// Explanation:
// Inner substring “2[ca]” breakdown into “caca”.
// Now, new string becomes “3[bcaca]”
// Similarly “3[bcaca]” becomes “bcacabcacabcaca” which is final result.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodedString(string &s) {
        string ans = "";
        stack<char> st;

        for (char ch : s) {
            if (ch == ']') {
                string curr_str = "";

                // Get string inside brackets.
                while (!st.empty() && st.top() != '[') {
                    curr_str.push_back(st.top());
                    st.pop();
                }

                st.pop(); // Remove '['

                string num = "";

                // Get repetition count.
                while (!st.empty() && isdigit(st.top())) {
                    num.push_back(st.top());
                    st.pop();
                }

                reverse(num.begin(), num.end());
                int Freq = stoi(num);

                // Restore string order.
                reverse(curr_str.begin(), curr_str.end());

                string final_str = "";

                // Repeat the string.
                while (Freq--) {
                    final_str += curr_str;
                }

                // Push decoded string back.
                for (char c : final_str)
                    st.push(c);

            } 
            else {
                st.push(ch);
            }
        }

        // Build answer from stack.
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};