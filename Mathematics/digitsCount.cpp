//Total digits in 1 to n
//Given a number n, count the total number of digits required to write all numbers from 1 to n.

// Examples:
// Input: n = 13
// Output: 17 
// Explanation: There are total 17 digits required to write all numbers from 1 to 13 ,i.e., 
// Numbers from 1 to 9 → each has 1 digit → contributes 9×1=9.
// Numbers from 10 to 99 → each has 2 digit → contributes 99×2=180.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalDigits(int n) {
        int digits = 0;
        int length = 1;   // current digit length
        int start = 1;    // starting number of this range
        
        while (start <= n) {
            int end = min(n, start * 10 - 1); // upper bound for this digit length
            int count = end - start + 1;      // how many numbers in this range
            digits += count * length;         // contribution
            start *= 10;                      // move to next digit length
            length++;
        }
        return digits;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    cout << sol.totalDigits(n) << endl;
    return 0;
}


