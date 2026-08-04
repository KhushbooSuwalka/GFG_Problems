//Given a string s, return true if the string is a palindrome. Otherwise, return false.
// A string is considered a palindrome if it reads the same forwards and backwards.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPalindrome(string& s) {
        string original = s;
        int i=0;
        int j=s.size()-1;
        
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        
        if(original==s){
            return true;
        }else{
            return false;
        }
        
    }
};