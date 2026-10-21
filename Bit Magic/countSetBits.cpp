//Given a positive integer n. Return the count of set bits in its binary equivalent.

// Examples:
// Input: n = 6
// Output: 2
// Explanation: Binary representation is '110', so the count of the set bit is 2.

#include <bits/stdc++.h>
using namespace std;

// Approach 1 :- Using Brian Kernighan's Algorithm

class Solution {
  public:
    int setBits(int n) {
        int count=0;
        //Continue until all set bits are removed
        while(n>0){
            n = n&(n-1); // Remove the rightmost set bit.
            count++;
        }
        return count;
    }
};

// Approach 2 :- 

class Solution {
  public:
    int setBits(int n) {
        int count=0;
        //Traverse all bits of the number.
        while(n>0){
            //If the last bit is set, increment the count.
            if (n & 1)
                count++;

            // Move to the next bit.
            n >>= 1;
        }
        return count;
    }
};

// Approach 3 :- Using __builtin_popcount() function

class Solution {
  public:
    int setBits(int n) {
        //returns number of set bits
        return __builtin_popcount(n);
    }
};