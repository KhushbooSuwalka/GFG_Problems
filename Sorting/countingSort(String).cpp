//Given a string s consisting of lowercase english letters, arrange all its letters in lexicographical order using Counting Sort.

// Examples:
// Input: s = "edsab"
// Output: abdes
// Explanation: In lexicographical order, s will be abdes.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string countSort(string s) {
        int count[26] = {0};
        
        for(char ch : s){
            count[ch-'a']++;
        }
        
        string result = "";
        
        for(int i=0;i<26;i++){
            while(count[i]>0){
                result += char('a'+i);
                count[i]--;
            }
        }
        
        return result;
    }
};