//Given a positive integer n, you need to count the numbers less than or equal to n having exactly 9 divisors.

// Examples :
// Input: n = 100
// Output: 2
// Explanation: Numbers which have exactly 9 divisors are 36 and 100.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNumbers(int n) {
        int limit = sqrt(n);

        // Step 1: Sieve
        vector<bool> isPrime(limit + 1, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i * i <= limit; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Step 2: Store primes
        vector<int> primes;

        for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        int ans = 0;

        // Step 3: Count p^8
        for (int p : primes) {
            long long val = 1;
            bool valid = true;

            for (int k = 0; k < 8; k++) {
                if (val > n / p) {
                    valid = false;
                    break;
                }

                val *= p;
            }

            if (valid) {
                ans++;
            }
        }

        // Step 4: Count p^2 * q^2
        int i = 0;
        int j = primes.size() - 1;

        while (i < j) {
            long long product = 1LL * primes[i] * primes[j];

            if (product <= limit) {
                ans += (j - i);
                i++;

            } else {
                j--;
            }
        }

        return ans;
    }
};