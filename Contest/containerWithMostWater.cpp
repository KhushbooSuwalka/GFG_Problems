// Container With Most Water
//Given an array arr[] of non-negative integers, where each element arr[i] represents the height of the vertical lines, find the maximum amount of water that can be contained between any two lines, together with the x-axis.
//Note: In the case of a single vertical line it will not be able to hold water.

#include<bits/stdc++.h>
using namespace std;

int maxWater(vector<int> &arr) {
  	int left = 0, right = arr.size() - 1;
    int maxArea = 0;
    while(left < right) {
        
        // find the water stored in the container between arr[left] and arr[right]
        int water = min(arr[left], arr[right]) * (right - left);     
        //width = right - left, height = min(arr[left], arr[right]) ,area = width * height ,water is thearea of water.
        
        maxArea = max(maxArea, water);
      
        if(arr[left] < arr[right])
            left += 1;
        else
            right -= 1;
    }
  
    return maxArea;
}