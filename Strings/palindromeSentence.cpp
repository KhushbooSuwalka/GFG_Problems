//Given a single string s, the task is to check if it is a palindrome sentence or not.
// A palindrome sentence is a sequence of characters, such as word, phrase, or series of symbols that reads the same backward as forward after converting all uppercase letters to lowercase and removing all non-alphanumeric characters (including spaces and punctuation).

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPalinSent(string &s) {
        int i=0;
        int j=s.size()-1;
        
        while(i<j){
            if(!isalnum(s[i])){
                i++;
            }
            
            else if(!isalnum(s[j])){
                j--;
            }
            
            else if(tolower(s[i])==tolower(s[j])){
                i++;
                j--;
            }
            
            else{
                return false;
            }
            
        }
        
        return true;
        
    }
};