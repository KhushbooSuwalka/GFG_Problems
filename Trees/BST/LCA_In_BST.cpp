//Given a Binary Search Tree (BST) with unique node values and two nodes n1 and n2 (n1 != n2), find their Lowest Common Ancestor (LCA).
// The Lowest Common Ancestor (LCA) of two nodes is defined as the deepest node in the tree that has both n1 and n2 as descendants, where a node can be a descendant of itself.

// Examples:
// Input: root = [5, 4, 6, 3, N, N, 7, N, N, N, 8], n1->data = 7, n2->data = 8
// Output: 7

#include<bits/stdc++.h>
using namespace std;

class Node {
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

class Solution {
  public:
    Node* findLCA(Node* root, Node* n1, Node* n2) {
        if(root==NULL)  return root;
        
        // If both n1 and n2 are smaller than root, go to left subtree
        if(n1->data < root->data && n2->data < root->data){
            return findLCA(root->left,n1,n2);
        }
        
        // If both n1 and n2 are greater than root, go to right subtree
        if(n1->data > root->data && n2->data > root->data){
            return findLCA(root->right,n1,n2);
        }
        
        // If nodes n1 and n2 are on the opposite sides, then root is the LCA
        return root;
    }
};