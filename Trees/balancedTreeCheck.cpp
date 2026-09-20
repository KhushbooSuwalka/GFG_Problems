//Given the root of a binary tree, determine if it is height-balanced or not.
// Note: A binary tree is considered height-balanced if the absolute difference in heights of the left and right subtrees is at most 1 for every node in the tree.

// Examples:
// Input: root = [10, 20, 30, 40, 60]
// Output: true 
// Explanation: The height difference between the left and right subtrees at all nodes is at most 1. Hence, the tree is balanced.

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Approach 1: Using DFS

class Solution {
  public:
    int height(Node* root) {
        if (root == nullptr) {
            return -1;
        }
        return 1 + max(height(root->left), height(root->right));
    }

    bool solve(Node* root){
        // Base case: If the current node is null, it is balanced
        if(root == NULL){
            return true;
        }
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);  

        // Check current node
        if(abs(leftHeight - rightHeight) > 1){
            return false;
        }

        // Recursively Check both subtrees
        return solve(root->left) && solve(root->right);
    }
    
    bool isBalanced(Node* root) {
        return solve(root);
    }
};

// Approach 2: Using DFS with height calculation in a single traversal

class Solution {
  public:
    int solve(Node* root){
        // Base case: 
        if(root == NULL){
            return -1;
        }
        
        // Get left subtree height
        int leftHeight = solve(root->left);
        // Left subtree is unbalanced
        if(leftHeight == -2){
            return -2;
        }

        // Get right subtree height
        int rightHeight = solve(root->right);
        // Right subtree is unbalanced
        if(rightHeight == -2){
            return -2;
        }

        // Height difference > 1
        if(abs(leftHeight - rightHeight) > 1){
            return -2;
        }

        // Return the height of the current node
        return 1 + max(leftHeight, rightHeight);
    }
    
    bool isBalanced(Node* root) {
        return solve(root) != -2;
    }
};