// Product array puzzle (Product of Array Except Self)
// Given an array arr[] of n integers, construct a product array res[] (of the same size) such that res[i] is equal to the product of all the elements of arr[] except arr[i]. 

#include<bits/stdc++.h>
using namespace std;

//Approach 1: Nested Loop(Brute Force Approach)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            int product = 1;

            for (int j = 0; j < n; j++) {
                if (i != j) {
                    product *= arr[j];
                }
            }

            res[i] = product;
        }

        return res;
    }
};

//Approach 2: — Prefix and Suffix Arrays

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();

        vector<int> prefix(n);
        vector<int> suffix(n);
        vector<int> res(n);

        // Prefix product
        prefix[0] = 1;

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * arr[i - 1];
        }

        // Suffix product
        suffix[n - 1] = 1;

        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * arr[i + 1];
        }

        // Calculate result
        for (int i = 0; i < n; i++) {
            res[i] = prefix[i] * suffix[i];
        }

        return res;
    }
};

//Approach 3:- Product Array

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, 1);

        // Step 1: Store prefix products
        int prefix = 1;

        for (int i = 0; i < n; i++) {
            res[i] = prefix;
            prefix = prefix * arr[i];
        }

        // Step 2: Add suffix products
        int suffix = 1;

        for (int i = n - 1; i >= 0; i--) {
            res[i] = res[i] * suffix;
            suffix = suffix * arr[i];
        }

        return res;
    }
};