//You are given a string s, and your task is to reverse the string.
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string reverseString(string& s) {
        int i=0;
        int j=s.size()-1;
        
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        
        return s;    
    }
};
