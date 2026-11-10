//Given an array arr[] of n elements in the form {a1, a2, a3, ..., a(n/2), b1, b2, b3, ..., b(n/2)}, rearrange the array in place to {a1, b1, a2, b2, a3, b3, ..., a(n/2), b(n/2)} without using extra space.
//Note: n is always even.

// Examples:
// Input: arr[] = [1, 2, 9, 15]
// Output: [1, 9, 2, 15]
// Explanation: Here a1 = 1, a2 = 2, b1 = 9, b2 = 15. The final array becomes a1, b1, a2, b2 = [1, 9, 2, 15]

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void shuffleArray(vector<int>& arr) {
        int n = arr.size();
        int mid = n / 2;
        
        int base = 1001;
        
        // Store shuffled values in encoded form
        for(int i = 0; i < n; i++) {
            int destination;
            
            if(i < mid) {
                destination = 2 * i;
            } else {
                destination = 2 * (i - mid) + 1;
            }
            
            arr[destination] += (arr[i] % base) * base;
        }
        
        // Extract the shuffled values
        for(int i = 0; i < n; i++) {
            arr[i] = arr[i] / base;
        }
    }
};
