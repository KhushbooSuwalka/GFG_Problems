// Given an integer n, return all the divisors of n in the ascending order.
 
// Examples:
// Input : n = 20
// Output: 1 2 4 5 10 20
// Explanation: 20 is completely divisible by 1, 2, 4, 5, 10 and 20.

#include <bits/stdc++.h>
using namespace std;

// Approach 1:-

vector<int> getDivisors(int n) {
    vector<int> ans;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i);
        }
    }

    return ans;
}

// Approach 2:-

vector<int> divisors(int n) {
    vector<int> ans;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i);

            if (i != n / i) {
                ans.push_back(n / i);
            }
        }
    }

    sort(ans.begin(), ans.end());

    return ans;
}