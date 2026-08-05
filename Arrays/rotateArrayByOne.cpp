//Given an array arr, rotate the array by one position in clockwise direction.
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void rotate(vector<int> &arr) {
        int n=arr.size();
        int temp=arr[n-1];
        
        int i=0;
        int j=n-1;
        while(i<j){
            arr[j]=arr[j-1];
            j--;
        }
        arr[0]=temp;
    }
};