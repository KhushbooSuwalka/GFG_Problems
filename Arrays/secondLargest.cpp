#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int largest = -1,secondLargest = -1;
        int n=arr.size();
        int i=0;

        while(i<n){
            if(arr[i]>largest){
                secondLargest=largest;
                largest=arr[i];
            }
            else if(arr[i]!=largest && arr[i]>secondLargest){
                secondLargest=arr[i];
            }
            i++;
        }     
        return secondLargest;
    }
};