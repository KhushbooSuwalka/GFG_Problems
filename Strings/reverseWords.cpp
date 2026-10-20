//Given a string s, reverse the string without reversing its individual words. Words are separated by dots(.).
// 1. The string may contain leading or trailing dots(.) or multiple dots(.) between two words.
// 2. The returned string should only have a single dot(.) separating the words and no extra dots should be included.

// Examples :
// Input: s = "i.like.this.program.very.much"
// Output: "much.very.program.this.like.i"

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string reverseWords(string &s) {
        string ans;
        string word;
        vector<string> a;
        
        for(char ch:s){
            if(ch=='.'){
                if(!word.empty()){
                    a.push_back(word);
                    word="";
                }
                continue;
            }
            word+=ch;
        }
        
        if(!word.empty()){
            a.push_back(word);
        }
        
        int m=a.size();
        for(int i=m-1;i>=0;i--){
            ans+=a[i];
            if(i!=0){
                ans+=".";
            }
        }
        
        return ans;
    }
};