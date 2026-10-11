//Given an array arr[] of non-negative numbers. Each number tells you the maximum number of steps you can jump forward from that position.
// For example:
// 1. If arr[i] = 3, you can jump to index i + 1, i + 2, or i + 3 from position i.
// 2. If arr[i] = 0, you cannot jump forward from that position.
// Find the minimum number of jumps needed to move from the first position in the array to the last position.
// Note:  Return -1 if you can't reach the end of the array.

// Examples : 
// Input: arr[] = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]
// Output: 3 
// Explanation: First jump from 1st element to 2nd element with value 3. From here we jump to 5th element with value 9, and from here we will jump to the last. 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {  
        int n = arr.size();

        // Agar starting position se hi aage nahi ja sakte
        if(arr[0] == 0)
            return -1;

        int maxReach = arr[0];
        int steps = arr[0];
        int jumps = 1;

        // Last element tak pahunchna hai
        for(int i = 1; i < n; i++) {

            // Agar last element tak pahunch gaye
            if(i == n - 1)
                return jumps;

            // Is position se maximum kaha tak pahunch sakte hain
            maxReach = max(maxReach, i + arr[i]);

            // Ek step use kar liya
            steps--;

            // Current jump ki range khatam ho gayi
            if(steps == 0) {
                // Agar aage jaane ka koi way nahi hai
                if(i >= maxReach)
                    return -1;

                // Naya jump
                jumps++;

                // New range ke steps
                steps = maxReach - i;
            }
        }

        return -1;
    }
};