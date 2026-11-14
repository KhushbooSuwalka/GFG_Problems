//Given two strings s1 and s2, of equal lengths. The task is to check if s2 is a rotated version of the string s1.
// Note: A string is a rotation of another if it can be formed by moving characters from the start to the end (or vice versa) without rearranging them.

// Examples :
// Input: s1 = "abcd", s2 = "cdab"
// Output: true
// Explanation: After 2 right rotations, s1 will become equal to s2.

#include <bits/stdc++.h>
using namespace std;

bool areRotations(string &s1, string &s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    
    // Concatenate s1 with itself
    string concatenated = s1 + s1;
    
    // Check if s2 is a substring of the concatenated string
    return (concatenated.find(s2) != string::npos);
}