//Longest Substring with Distinct Characters
//Given a string s, find the length of the longest substring with all distinct characters.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestUniqueSubstring(string &s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            bool visited[256] = {false};

            for (int j = i; j < n; j++) {

                if (visited[s[j]]) {
                    break;
                }

                visited[s[j]] = true;

                ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};

//Approach 2:- Using sliding window

class Solution {
public:
    int longestUniqueSubstring(string &s) {
        int n = s.size();
        int left = 0;
        int ans = 0;

        bool visited[256] = {false};

        for (int right = 0; right < n; right++) {

            while (visited[s[right]]) {
                visited[s[left]] = false;
                left++;
            }

            visited[s[right]] = true;

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

//Approach 3:- Using sliding window and unordered_set --> Submitted

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int n = s.size();
        int i=0,j=0,ans=0;
        
        unordered_set<char> st;
        
        for(j=0;j<n;j++){
            
            // If duplicate character is found
            while(st.find(s[j]) != st.end()){
                st.erase(s[i]);
                i++;
            }
            
            st.insert(s[j]);
            
            ans = max(ans,j-i+1);
            
        }
        
        return ans;
        
    }
};

//Approach 4 :- Using Last Index of Each Character

class Solution {
public:
    int longestUniqueSubstring(string &s) {
        int n = s.size();
        int lastIndex[256];

        for (int i = 0; i < 256; i++) {
            lastIndex[i] = -1;
        }

        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            left = max(left, lastIndex[s[right]] + 1);
            ans = max(ans, right - left + 1);
            lastIndex[s[right]] = right;
        }

        return ans;
    }
};