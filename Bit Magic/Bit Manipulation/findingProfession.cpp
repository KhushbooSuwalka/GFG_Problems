//Consider a special family of Engineers and Doctors with following rules :
// 1. Everybody has two children.
// 2. First child of an Engineer is an Engineer and second child is a Doctor.
// 3. First child of an Doctor is Doctor and second child is an Engineer.
// 4. All generations of Doctors and Engineers start with Engineer.

// The first few levels of the family tree are shown below :
// Given the 1-based level and pos (position from left) of a person in above ancestor tree, return their profession as a string: either "Engineer" or "Doctor".

// Examples:
// Input: level = 4, pos = 2
// Output: Doctor

// Approach 1 :-

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string profession(int level, int pos) {
        int count = 0;
        while(pos > 1) {
            if(pos % 2 == 0) {
                count++;
            }
            pos = (pos + 1) / 2;
        }

        if(count % 2 == 0) {
            return "Engineer";
        }
        return "Doctor";
    }
};

// Approach 2 :- Using Recursion + Binary Tree + Bit Manipulation.

int countSetBits(int n){
    int count = 0;
    while (n){
        n &= (n-1);
        count++;
    }
    return count;
}

string profession(int level, int pos){
    int c = countSetBits(pos-1);
    return ((c % 2) ? "Doctor" : "Engineer");
}