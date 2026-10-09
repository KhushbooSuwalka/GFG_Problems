// You are given the root of a binary tree, and the task is to determine whether it satisfies the properties of a max-heap.
// A binary tree is considered a max-heap if it satisfies the following conditions:
// 1. Completeness: Every level of the tree, except possibly the last, is completely filled, and all nodes are as far left as possible.
// 2. Max-Heap Property: The value of each node is greater than or equal to the values of its children.

// Examples:
// Input: root = [97, 46, 37, 12, 3, 7, 31, 6, 9]
// Output: true
// Explanation: The tree is complete and satisfies the max-heap property.

#include<stdio.h>
using namespace std;

class Node{
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
    // Total nodes count karne ke liye
    int countNodes(Node* root) {
        if (root == NULL)
            return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // Check complete binary tree
    bool isComplete(Node* root, int index, int totalNodes) {
        if (root == NULL)
            return true;

        // Agar index total nodes se >= hai matlab tree complete nahi hai
        if (index >= totalNodes)
            return false;

        return isComplete(root->left, 2 * index + 1, totalNodes) && isComplete(root->right, 2 * index + 2, totalNodes);
    }

    // Check Max-Heap property
    bool isMaxHeap(Node* root) {
        if (root == NULL)
            return true;

        // Left child exists and is greater than parent
        if (root->left != NULL && root->left->data > root->data)
            return false;

        // Right child exists and is greater than parent
        if (root->right != NULL && root->right->data > root->data)
            return false;

        return isMaxHeap(root->left) && isMaxHeap(root->right);
    }

    bool isHeap(Node* tree) {
        int totalNodes = countNodes(tree);

        // First check completeness
        if (!isComplete(tree, 0, totalNodes))
            return false;

        // Then check max-heap property
        if (!isMaxHeap(tree))
            return false;

        return true;
    }
};