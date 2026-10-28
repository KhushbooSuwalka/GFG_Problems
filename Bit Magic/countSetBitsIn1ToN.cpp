//Given a number n. Return the total count of set bits for all numbers from 1 to n (both inclusive).

// Examples :
// Input: n = 4
// Output: 5
// Explanation: For numbers from 1 to 4. for 1: 0 0 1 => 1 set bit, for 2: 0 1 0 => 1 set bit, for 3: 0 1 1 => 2 set bits, for 4: 1 0 0 => 1 set bit. Therefore, the total set bits are 5.

#include <bits/stdc++.h>
using namespace std;

// Approach 1 :- 

class Solution {
  public:
    int setBits(int n) {
		int count = 0;
		while (n) {
			count += n & 1;
			n >>= 1;
		}
		return count;
	}
	
    int countSetBits(int n) {
        int res = 0;
        for (int i=1; i<=n; i++)
           res += setBits(i);
        return res;   
    }
};

// Approach 2 :-

class Solution {
  public:
    int countSetBits(int n) {
       long long ans = 0;
       for (long long power = 1; power <= n; power *= 2) {
           long long cycle = power * 2;

           long long fullCycles = (n + 1) / cycle;
           long long remainder = (n + 1) % cycle;

           ans += fullCycles * power;

           if (remainder > power) {
               ans += remainder - power;
           }
       }

       return ans;
    }
};