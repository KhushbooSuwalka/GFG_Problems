//Given two arrays a[] and b[], your task is to determine whether b[] is a subset of a[].

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isSubset(vector<int> &a, vector<int> &b) {
        unordered_map<int,int> freq;
        
        for(int i=0;i<a.size();i++){
            freq[a[i]]++;
        }
        
        for(int i=0;i<b.size();i++){
            if(freq.find(b[i])==freq.end()){
                return false;
            }else{
                freq[b[i]]--;
                if(freq[b[i]]==0){
                    freq.erase(b[i]);
                }
            }
        }
        
        return true; 
    }
};

//Approach 2 :- Using nested loops

class Solution {
  public:
    bool isSubset(vector<int> &a, vector<int> &b, int n, int m) {
        for(int i=0;i<m;i++){
            bool found = false;
            for(int j=0;j<n;j++){
                if(b[i]==a[j]){
                    found = true;
                    break;
                }
            }
            if(!found){
                return false;
            }
        }
        
        return true;
    }
};

//Approach 3 :- Using sorting and two pointer technique

class Solution {
  public:
    bool isSubset(vector<int> &a, vector<int> &b, int n, int m) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int i = 0, j = 0;
        
        while(i<n && j<m){
            if(a[i]<b[j]){
                i++; 
            }
            else if(a[i]==b[j]){
                i++;
                j++;
            }
            else{
                return false;
            }
        }
        
        if(j==m){
            return true;
        }
        
        return false;
    }
};