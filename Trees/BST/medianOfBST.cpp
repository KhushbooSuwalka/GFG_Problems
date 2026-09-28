//You are given the root of a Binary Search Tree, find the median of it.  Let the nodes of the BST, when written in ascending order (inorder traversal), be represented as V1, V2, V3, …, Vn, where n is the total number of nodes in the BST.
// If number of nodes are even: return V(n/2).
// If number of nodes are odd: return V((n+1)/2).

// Examples:
// Input: root[] = [20, 8, 22, 4, 12, N, N, N, N, 10, 14]
// Output: 12
// Explanation: The inorder of given BST is 4, 8, 10, 12, 14, 20, 22. Here, n = 7, so, here median will be ((7+1)/2)th value, i.e., 4th value, i.e, 12.

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

    // Count total number of nodes
    int countNodes(Node* root) {
        if (root == NULL)
            return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // Find kth smallest element
    void inorder(Node* root, int &k, int &ans) {
        if (root == NULL)
            return;

        inorder(root->left, k, ans);
        k--;

        if (k == 0) {
            ans = root->data;
            return;
        }

        inorder(root->right, k, ans);
    }

    int findMedian(Node* root) {
        int n = countNodes(root);

        // For both odd and even n, we need the lower middle element
        int k = (n + 1) / 2;
        int ans = -1;

        inorder(root, k, ans);
        return ans;
    }
};