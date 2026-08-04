// Given an array arr of only 0's and 1's. The array is sorted in such a manner that all the 1's are placed first and then they are followed by all the 0's. Find the count of all the 0's.

#include<bits/stdc++.h>
using namespace std;

int countZeroes(vector<int> arr){
    int count = 0;
    int i =0;
    int j = arr.size()-1;
    while(i<j){
        if(arr[i]==0)
            count++;
        if(arr[j]==0)
            count++;
        i++;
        j--;
    }
    if(i==j && arr[i]==0)
        count++;
    return count;
}

// Approach 2:- By Binary Search ,search the first index of 0 and then return the count of zeroes by (arr.size()-first) else return 0