//Given the root of a binary tree, find the maximum path sum. The path may start and end at any node in the tree.

// Examples:
// Input: root[] = [10, 2, 10, 20, 1, N, -25, N, N, N, N, 3, 4]
// Output: 42
// Explanation: Max path sum is represented using green colored nodes in the above binary tree.

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    int maxPathSumUtil(Node* root, int& res) {
        if (root == nullptr)
            return 0;

        int left = max(0, maxPathSumUtil(root->left, res));
        int right = max(0, maxPathSumUtil(root->right, res));

        res = max(res, left + right + root->data);

        return root->data + max(left, right);
    }

    int findMaxSum(Node *root) {
        int res = INT_MIN;
        maxPathSumUtil(root, res);
        return res;
    }
};