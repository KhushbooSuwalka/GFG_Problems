// Given an integer n, determine if it is a Lucky Number.
// Lucky numbers are identified using a elimination process on the infinite sequence of natural numbers (1, 2, 3, 4, ...):
// 1. Remove every 2nd number from the sequence.
// 2. From the remaining sequence, remove every 3rd number.
// 3. From the remaining sequence, remove every 4th number, and so on...

// This continues indefinitely. Return true if n survives the elimination process (is a lucky number). Otherwise, return false.

// Examples :
// Input: n = 5
// Output: false
// Explanation: 5 is not a lucky number as it gets deleted in the second iteration.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isLucky(int n) {
        
        // Generate the initial sequence from 1 to n
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) { 
            nums[i] = i + 1; 
        }
        
        int k = 2; 
        
        // Continue eliminating while the step size is valid 
        while (k <= nums.size()) {
            
            // Use a temporary vector to store surviving numbers 
            vector<int> next_nums; 
            for (int i = 0; i < nums.size(); i++) { 
                
                // Keep the number if its 1-based position is NOT a multiple of k 
                if ((i + 1) % k != 0) { 
                    next_nums.push_back(nums[i]); 
                } 
                
            } 
            
            // Update our main sequence to the newly filtered one 
            nums = next_nums; 
            k++; 
            
        }
        
        // Check if 'n' survived by searching for it in the remaining numbers 
        return find(nums.begin(), nums.end(), n) != nums.end();
    }
};

// Approach 2 :- Submitted

class Solution {
public:
    bool isLucky(int n) {
        int counter = 2;

        while (counter <= n) {
            
            // Find the position of n
            if (n % counter == 0)
                return false;

            // Move n to its position after elimination
            n = n - (n / counter);

            counter++;
        }

        return true;
    }
};