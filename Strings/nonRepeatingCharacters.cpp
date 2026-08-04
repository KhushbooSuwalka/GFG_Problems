//Given a string s consisting of lowercase English Letters. return the first non-repeating character in s. If there is no non-repeating character, return '$'.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    char nonRepeatingChar(string &s) {
        unordered_map<char,int> freq;
        
        for(char ch:s){
            freq[ch]++;
        }
        
        for(char ch:s){
            if(freq[ch]==1){
                return ch;
            }
        }
        
        return '$';
    }
};