//Given the root of a binary tree with all unique values and two nodes value, n1 and n2.
// Find the lowest common ancestor of the given two nodes. Both node values are always present in the Binary Tree.
// Note: LCA is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

// Examples:
// Input: root = [1, 2, 3, 4, 5, 6, 7], n1 = 4, n2 = 5    
// Output: 2

#include<bits/stdc++.h>
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
    Node* solve(Node* root,int n1,int n2){
        if(!root) return NULL;

        //current node is one of the targets
        if(root->data == n1 || root->data == n2) return root;

        Node* left = solve(root->left,n1,n2);
        Node* right = solve(root->right,n1,n2);

        //p & q are present in one of the sides
        if(left && right) return root;

        //return krdo jo bhi non null node ho usse
        return left ? left : right;

    }

    Node* lca(Node* root, int n1, int n2) {
        return solve(root,n1,n2);
    }
};