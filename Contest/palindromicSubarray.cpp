//Operations to make palindromic subarray
//You are given an integer array arr[]. Your task is to consider every subarray of arr[] individually and determine the minimum number of operations required to convert each subarray into a palindromic sequence.
// In one operation, you can change any one element of the subarray to any integer.
// Operations are local to the subarray and do not affect the original array or any other subarrays.
// Each subarray is treated independently.
// A palindromic sequence is one that reads the same forwards and backwards (e.g., [1, 2, 2, 1], [7]).
// Note: Each number in the array appears at most 100 times.

//Input : arr[] = [1, 2, 2]
// Output : 2
// Explanation : Operations required for each subarray are :
// For subarray [1] : 0 operation is required.
// For subarray [2] : 0 operation is required.
// For subarray [2] : 0 operation is required.
// For subarray [1, 2] : 1 operation is required.
// For subarray [2, 2] : 0 operation is required.
// For subarray [1, 2, 2]: 1 operation is required.
// Total number of minimum operations required independentally to make all subarrays palindromic is (0 + 0 + 0 + 1 + 0 + 1) = 2. 

#include <bits/stdc++.h>
using namespace std;

