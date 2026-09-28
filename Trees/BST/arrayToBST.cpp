//Given a sorted array arr[]. Convert it into a Height Balanced Binary Search Tree (BST) and return the root of the BST.
// Height-balanced BST means a binary tree in which the depth of the left subtree and the right subtree of every node never differ by more than 1.
// Note: You can return any BST, the driver code will check the BST, and print true if it is a Height-balanced BST else print false.

// Examples :
// Input: arr[] = [10, 20, 30]
// Output: true
// Explanation: Only possible Height Balanced BST will be [20, 10, 30]

#include<bits/stdc++.h>
using namespace std;

class Node{
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
    Node* solve(vector<int>& arr, int left, int right) {
        if (left > right)
            return NULL;

        int mid = left + (right - left) / 2;

        Node* root = new Node(arr[mid]);
        root->left = solve(arr, left, mid - 1);
        root->right = solve(arr, mid + 1, right);
        return root;
    }

    Node* sortedArrayToBST(vector<int>& arr) {
        return solve(arr, 0, arr.size() - 1);
    }
};