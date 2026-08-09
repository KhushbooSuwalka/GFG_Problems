//You are given an array arr[] of integers of length n. An array is considered as a balanced if
// 1. Elements at odd indices (1-based indexing) are odd integers.
// 2. Elements at even indices (1-based indexing) are even integers.

// To achieve a balanced array, you are allowed to perform the following operation any number of times:
// 1. Select any two indices (i, j) in the array and swap their elements arr[i] and arr[j] with cost arr[i] + arr[j].
// Your task is to find minimum cost possible to achieve a balanced array from given array if is possible, otherwise return -1.

// Examples:
// Input: arr[] = [4, 3, 2, 1]
// Output: 10
// Explanation: Swap 4 with 3 and 2 with 1. After these swaps, the array becomes balanced, and the total cost is 7+3 = 10.
// Input: arr[] = [1, 2, 3, 4]
// Output: 0
// Explanation: Given array is already balanced.
// Input: arr[] = [1, 1, 1]
// Output: -1

#include<bits/stdc++.h>
using namespace std;

long long getMinBalancingCost(vector<int>& arr) {
    
    long long cost = 0;
    
    int wrongEven = 0;
    int wrongOdd = 0;

    for (int i = 0; i < arr.size(); i++) {
        
        // 1-based index is i + 1
        
        if ((i + 1) % 2 == 1) {
            
            // Odd index should contain odd number
            if (arr[i] % 2 == 0) {
                wrongEven++;
                cost += arr[i];
            }
        }
        else {
            
            // Even index should contain even number
            if (arr[i] % 2 == 1) {
                wrongOdd++;
                cost += arr[i];
            }
        }
    }

    // Number of mismatches must be equal
    if (wrongEven != wrongOdd)
        return -1;

    return cost;
}

int main() {
    vector<int> arr = {3, 2, 4, 5, 7, 6}; 
    cout << "Minimum Balancing Cost: " << getMinBalancingCost(arr) << endl;
    return 0;
}