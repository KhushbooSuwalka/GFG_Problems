//Given the array arr[] of heights of certain buildings that lie adjacent to each other, Sunlight starts falling from the left side of the buildings. If there is a building of a certain height, all the buildings to the right side of it having lesser heights cannot see the sun. Find the total number of buildings that receive sunlight.
// Note: Buildings with equal height do not block each other and can also receive sunlight.

// Examples:
// Input: arr[] = [6, 2, 8, 4, 11, 13]
// Output: 4
// Explanation: Only the buildings with heights 6, 8, 11, and 13 receive sunlight; therefore, the output is 4.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        int count = 1 ;
        int maxi = arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]>=maxi){
                count++;
                maxi = arr[i];
            }
        }
        return count ;
    }
};