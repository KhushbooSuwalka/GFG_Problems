//Sieve of Eratosthenes Algorithm
//Given a number n, find all prime numbers less than or equal to n.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sieve(int n) {
        vector<int> ans;
        vector<bool> prime(n + 1, true);

        for (int i = 2; i <= n; i++) {
            if (prime[i]) {
                ans.push_back(i);
                for (int j = i * 2; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }

        return ans;
    }
};