//Given the root of a binary Tree. Return the right view of the binary tree. The right view of a Binary Tree is the set of nodes visible when the tree is viewed from the right side.

// Examples :
// Input: root = [1, 2, 3, N, N, 4, 5]
// Output: [1, 3, 5]

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
    void solve(Node* root, int level, vector<int>& ans) {
        if (root == NULL) return;

        if (level == ans.size()) {
            ans.push_back(root->data);
        }

        solve(root->right, level + 1, ans);
        solve(root->left, level + 1, ans);
    }
    
    vector<int> rightView(Node* root) {
        vector<int> ans;
        solve(root, 0, ans);
        return ans;
    }
};