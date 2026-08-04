//Given an array arr[]. Your task is to find the minimum and maximum elements in the array.

#include<bits/stdc++.h>
using namespace std;

vector<int> getMinMax(vector<int> &arr) {
    // sort(arr.begin(),arr.end());
    // int i=0;
    // int j=arr.size()-1;
    // return {arr[i],arr[j]};
    int n = arr.size();
    int minElement = arr[0];
    int maxElement = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    
    return {minElement, maxElement};
}