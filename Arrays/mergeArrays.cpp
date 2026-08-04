// Merge without extra space - Medium level
//Given two sorted arrays a[] and b[] of size n and m respectively, the task is to merge them in sorted order without using any extra space. Modify a[] so that it contains the first n elements and modify b[] so that it contains the last m elements.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int i = a.size()-1;
        int j =0;
        while(i>=0 && j<b.size() && a[i]>b[j]){
            swap(a[i--],b[j++]);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
    }
};

// Approach 2