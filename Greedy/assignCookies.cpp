//You are given an array greed[], where greed[i] represents the minimum size of cookie required to satisfy the i-th child, and an array cookie[], where cookie[j] represents the size of the j-th cookie. Each child can receive at most one cookie. A child i will be satisfied if they receive a cookie j such that cookie[j] >= greed[i]. Your task is to determine the maximum number of children that can be satisfied.

// Examples:
// Input : greed[] = [1, 10, 3], cookie = [1, 2, 3]
// Output: 2
// Explanation: We can only assign cookie to the first and third child.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxChildren(vector<int> &greed, vector<int> &cookie) {
        sort(greed.begin(),greed.end());
        sort(cookie.begin(),cookie.end());
        
        int i=0; int j=0; int count=0;
        while(i<greed.size() && j<cookie.size()){
            //current cookie will satisfy the greed of current child
            if(greed[i]<=cookie[j]){
                i++; j++;
                count++;
            }else{
                j++;
            }
        }
        
        return count;
    }
};