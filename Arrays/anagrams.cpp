//Given two non-empty strings s1 and s2, consisting only of lowercase English letters, determine whether they are anagrams of each other or not.
//Two strings are considered anagrams if they contain the same characters with exactly the same frequencies, regardless of their order. For example, "listen" and "silent" are anagrams, while "hello" and "world" are not.

#include<bits/stdc++.h>
using namespace std;

//Approach 1: Using one frequency array

class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        
        if(s1.size() != s2.size())
            return false;
        
        int freq[26]={0};
        
        for(char ch : s1){
            freq[ch-'a']++;
        }
        
        for(char ch : s2){
            freq[ch-'a']--;
        }
        
        for(int i=0;i<26;i++){
            if(freq[i] != 0){
                return false;
            }
        }
        
        return true;
        
    }
};

//Approach 2: Using two frequency arrays

class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        
        if(s1.size() != s2.size())
            return false;
        
        int freq1[26]={0};
        int freq2[26]={0};
        
        for(char ch : s1){
            freq1[ch-'a']++;
        }
        
        for(char ch : s2){
            freq2[ch-'a']++;
        }
        
        for(int i=0;i<26;i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        
        return true;
        
    }
};

//Approach 3: Using Hash Map

class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        
        if(s1.size() != s2.size())
            return false;
        
        unordered_map<char,int> freq;
        
        for(char ch : s1){
            freq[ch]++;
        }
        
        for(char ch : s2){
            freq[ch]--;
        }
        
        for(auto it : freq){
            if(it.second != 0){
                return false;
            }
        }
        
        return true;
        
    }
};

//Approach 4: Using two hash maps

class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        
        if(s1.size() != s2.size())
            return false;
        
        unordered_map<char,int> freq1;
        unordered_map<char,int> freq2;
        
        for(char ch : s1){
            freq1[ch]++;
        }
        
        for(char ch : s2){
            freq2[ch]++;
        }
        
        for(auto it : freq1){
            if(freq2[it.first] != it.second){
                return false;
            }
        }
        
        return true;
        
    }
};

//Approach 5: Using unordered_set

class Solution {
public:
    bool areAnagrams(string& s1, string& s2) {
        // Length must be same
        if (s1.length() != s2.length()) {
            return false;
        }

        unordered_set<char> st;

        // Store distinct characters from s1
        for (char ch : s1) {
            st.insert(ch);
        }

        // Check frequency of each distinct character
        for (char ch : st) {

            int count1 = 0;
            int count2 = 0;

            // Count in s1
            for (char x : s1) {
                if (x == ch) {
                    count1++;
                }
            }

            // Count in s2
            for (char x : s2) {
                if (x == ch) {
                    count2++;
                }
            }

            // If frequency is different
            if (count1 != count2) {
                return false;
            }
        }

        return true;
    }
};