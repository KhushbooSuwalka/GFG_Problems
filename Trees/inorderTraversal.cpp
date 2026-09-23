//Given a root of a Binary Tree, your task is to return its Inorder Traversal.
// Note: An inorder traversal first visits the left child (including its entire subtree), then visits the node, and finally visits the right child (including its entire subtree).

// Examples:
// Input: root = [1, 2, 3, 4, 5]         
// Output: [4, 2, 5, 1, 3]

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    void solve(Node* root,vector<int> &ans){
        if(root==NULL){
            return;
        }
        
        solve(root->left,ans);
        ans.push_back(root->data);
        solve(root->right,ans);
    }
    
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};