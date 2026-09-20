//Given a root of binary tree having n nodes and an integer k, return all nodes that are at distance k from the root (root is considered at distance 0 from itself). Nodes should be returned from left to right.

// Examples:
// Input: k = 3, root = [1, 2, N, N, 1, 5, 3] 
// Output: 5 3
// Explanation:  5 and 3 are the nodes which are at distance 3 from the root 1, returned from left to right.

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
    void solve(Node* root, vector<int> &ans, int k) {
        if(root == NULL || k < 0) {
            return;
        }

        if(k == 0) {
            ans.push_back(root->data);
            return;
        }

        solve(root->left, ans, k - 1);
        solve(root->right, ans, k - 1);
    }
    
    vector<int> kdistance(Node *root, int k) {
        vector<int> ans;
        solve(root,ans,k);
        return ans;
    }
};