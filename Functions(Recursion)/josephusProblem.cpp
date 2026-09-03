//You are playing a game with n people standing in a circle, numbered from 1 to n. Starting from person 1, every kth person is eliminated in a circular fashion. The process continues until only one person remains.
// Given integers n and k, return the position (1-based index) of the person who will survive.

// Examples :
// Input: n = 5, k = 2
// Output: 3
// Explanation: Firstly, the person at position 2 is killed, then the person at position 4 is killed, then the person at position 1 is killed. 
// Finally, the person at position 5 is killed. So the person at position 3 survives. 
// Input: n = 7, k = 3
// Output: 4
// Explanation: The elimination order is 3 → 6 → 2 → 7 → 5 → 1, and the person at position 4 survives.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int solve(int n,int k){
        if (n==1){
            return 0 ;       //When there is only 1 person, that person's index is 0.
        }
        
        return (solve(n-1 , k) + k) % n;
    }
    
    int josephus(int n, int k) {
        return solve(n,k) + 1;  
        //Because The recursive function uses 0-based indexing , but in ques it is given that there is 1 based - position (index)    
    }
};