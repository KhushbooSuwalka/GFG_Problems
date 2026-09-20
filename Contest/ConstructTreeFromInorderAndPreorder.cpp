// Given two arrays representing the inorder and preorder traversals of a binary tree, construct the binary tree and return its root.
// Note: The inorder and preorder traversals contain unique values, and every value present in the preorder traversal is also found in the inorder traversal.  

// Examples:
// Input: inorder[] = [3, 1, 4, 0, 5, 2], preorder[] = [0, 1, 3, 4, 2, 5]
// Output: [0, 1, 2, 3, 4, 5]

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
    Node* solve(vector<int>& inorder, vector<int>& preorder, int inStart, int inEnd, int& preIndex) {
        // No element
        if(inStart > inEnd)
            return NULL;

        // First element of preorder is root
        int rootValue = preorder[preIndex];
        preIndex++;

        Node* root = new Node(rootValue);

        // Find root in inorder
        int pos = inStart;
        while(inorder[pos] != rootValue) {
            pos++;
        }

        // Build left subtree
        root->left = solve(inorder, preorder, inStart, pos - 1, preIndex);

        // Build right subtree
        root->right = solve(inorder, preorder, pos + 1, inEnd, preIndex);

        return root;
    }

    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        int preIndex = 0;
        return solve(inorder, preorder, 0, inorder.size() - 1, preIndex);
    }
};