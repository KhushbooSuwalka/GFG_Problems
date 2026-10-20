//Given a string s consisting of lowercase English letters. Each letter corresponds to a number on a standard keypad, as shown in the figure. Replace every character in s with its corresponding keypad number and return the resulting numeric string.

// Examples:
// Input: s = "geeksforgeeks"
// Output: 4335736743357

#include <bits/stdc++.h>
using namespace std;

//Approach 1 :- 

class Solution {
  public:
    string printNumber(string& s) {
        string ans="";
        string mp="22233344455566677778889999";
        for(char ch:s){
            ans+=mp[ch-'a'];
        }
        return ans;
    }
};

//Approach 2:-

class Solution {
  public:
    string printNumber(string& s) {
        string ans="";
        string keypad[]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        for(char ch:s){
            for(int i=0;i<8;i++){
                if(keypad[i].find(ch)!=string::npos){
                    ans+= char('2'+i);
                    break;
                }
            }
        }
        return ans;
    }
};