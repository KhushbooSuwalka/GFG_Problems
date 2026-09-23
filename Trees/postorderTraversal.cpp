//Given the root of a Binary Tree, return its Postorder Traversal.
// Note: A postorder traversal first visits the left child (including its entire subtree), then visits the right child (including its entire subtree), and finally visits the node itself.

// Examples:
// Input: root = [19, 10, 8, 11, 13]
// Output: [11, 13, 10, 8, 19]

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
        solve(root->right,ans);
        ans.push_back(root->data);
    }
    
    vector<int> postOrder(Node* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};