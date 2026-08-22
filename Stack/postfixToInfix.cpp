//You are given a string that represents the postfix form of a valid mathematical expression. Convert it to its infix form.

// Example:
// Input:
// ab*c+ 
// Output: 
// ((a*b)+c)

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string postToInfix(string &exp) {
        stack<string> num;
        
        for (char ch:exp){
            if(isalnum(ch)){
                num.push(string(1,ch));
            }else{
                string right = num.top();
                num.pop();
                
                string left = num.top();
                num.pop();
                
                string temp = "("+left+ch+right+")";
                num.push(temp);
            }
        }
        
        return num.top();
    }
};