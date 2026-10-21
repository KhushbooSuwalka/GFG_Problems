//Given a string s, check if it is a "Panagram" or not.  A "Panagram" is a sentence containing every letter in the English Alphabet either in lowercase or Uppercase.

// Examples:
// Input: s = "Bawds jog, flick quartz, vex nymph"
// Output: true
// Explanation: In the given string, there are all the letters of the English alphabet. Hence, the output is true.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool checkPangram(string& s) {
        vector<bool> vis(26,false);
        for(int i=0;i<s.length();i++){
            if(s[i]>='A' && s[i]<='Z'){
                vis[s[i]-'A']=true;
            }else if(s[i]>='a' && s[i]<='z'){
                vis[s[i]-'a']=true;
            }
        }
        
        for(int i=0;i<26;i++){
            if(!vis[i]){
                return false;
            }
        }
        
        return true;
    }
};