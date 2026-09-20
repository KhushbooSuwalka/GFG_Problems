//Given the root of a binary tree, find the maximum depth of the tree.
// Note: The maximum depth or height of the tree is the number of edges in the tree from the root to the deepest node.

// Examples:
// Input: root = [12, 8, 18, 5, 11]
// Output: 2
// Explanation: One of the longest path from the root(node 12) goes through node 8 to node 5, which has 2 edges.

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

class Solution {
  public:
    int height(Node* root) {
        if (root == NULL){
            return -1;
        }
        
        int left = height(root->left);
        int right = height(root->right);
        return 1 + max(left,right);  
    }
};