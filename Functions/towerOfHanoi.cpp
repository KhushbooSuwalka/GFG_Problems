// You are given n disks placed on a starting rod (from), with the smallest disk on top and the largest at the bottom. There are three rods: the starting rod(from), the target rod (to), and an auxiliary rod (aux).
//You have to calculate the minimum number of moves required to transfer all n disks from the starting rod to the target rod.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        if (n == 1)
            return 1;

        return 2 * towerOfHanoi(n - 1, from, aux, to) + 1;
    }
};