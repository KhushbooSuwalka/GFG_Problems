//Given a number n. Find its unique prime factors in increasing order.

// Examples :
// Input: n = 100
// Output: [2, 5]
// Explanation: Unique prime factors of 100 are 2 and 5.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> primeFac(int n) {
        vector<int> ans;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                ans.push_back(i);

                while (n % i == 0) {
                    n = n / i;
                }
            }
        }

        // Agar n > 1 hai, toh n khud prime hai
        if (n > 1) {
            ans.push_back(n);
        }

        return ans;
    }
};