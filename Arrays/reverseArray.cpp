#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // reverse(arr.begin(),arr.end());
        // return;
        int n = arr.size();
        int i=0,j=n-1;
        while (i<j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
        return;
    }
};