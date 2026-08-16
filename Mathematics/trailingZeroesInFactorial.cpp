//For an integer n, find the number of trailing zeroes in n!.

// Examples :
// Input: n = 5
// Output: 1
// Explanation: 5! = 120 so the number of trailing zero is 1.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int trailingZeroes(int n) {
        int count=0;
        int fact=1;
        for(int i=2;i<=n;i++){
            fact *= i ;
        }
        
        while(fact%10==0){
            count++;
            fact = fact/10;
        }
        
        return count;
    }
};

//Approach 2 :- Submitted

class Solution {
  public:
    int trailingZeroes(int n) {
        if(n<0){
            return -1;
        }
        
        int count =0;
        for(int i=5;n/i>=1;i*=5){
            count += n/i;
        }
        return count;
    }
};