//Given the root of a binary search tree and a number k, find the greatest number in the binary search tree that is less than or equal to k.
// Note: If no such node value exists that is smaller than k, then return -1.

// Examples:
// Input: root = [10, 7, 15, 2, 8, 11, 16],  k  =  14
// Output: 11
// Explanation: The greatest element in the tree which is less than or equal to 14, is 11.

#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Floor = greatest value that is <= k.
// Approach 1 :- Using Iterative Method

class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        int ans = -1;
        
        while(root != NULL) {
            if(root->data == k) {
                return root->data;
            }
            
            // Current value is smaller than k
            if(root->data < k) {
                ans = root->data;
                root = root->right;    // Try to find a bigger value
            }
            
            // Current value is greater than k
            else {
                root = root->left;     // Need a smaller value
            }
        }
        
        return ans;
    }
};

// Approch 2 :- Using recursion

class Solution {
  public:
    int floor(Node* root, int k) {
        if(root == NULL)
            return -1;
        
        // Exact value found
        if(root->data == k)
            return root->data;
        
        // If current value is greater than k, floor must be in left subtree
        if(root->data > k)
            return floor(root->left, k);
        
        // If current value is smaller than k, current node can be a possible floor
        int ans = floor(root->right, k);
        
        // If right subtree has no valid value, current node is the floor
        if(ans == -1)
            return root->data;
        
        return ans;
    }
};