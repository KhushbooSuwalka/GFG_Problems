//Given  a root of binary tree, check whether it is symmetric, i.e., whether the tree is a mirror image of itself.
// Note: A binary tree is symmetric if the left subtree is a mirror reflection of the right subtree.

// Examples:
// Input: root = [10, 5, 5, 2, N, N, 2] 
// Output: true
// Explanation: As the left and right half of the above tree is mirror image, the tree is symmetric.

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
    bool check(Node* left, Node* right) {
        // Both are NULL
        if(left == NULL && right == NULL)
            return true;

        // Only one is NULL
        if(left == NULL || right == NULL)
            return false;

        // Values are different
        if(left->data != right->data)
            return false;

        // Check mirror sides
        return check(left->left, right->right) &&
               check(left->right, right->left);
    }

    bool isSymmetric(Node* root) {
        if(root == NULL)
            return true;

        return check(root->left, root->right);
    }
};