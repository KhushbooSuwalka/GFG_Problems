//You are given the root of a complete binary tree. Your task is to find the count of nodes. A complete binary tree is a binary tree whose, all levels except the last one are completely filled, the last level may or may not be completely filled and Nodes in the last level are as left as possible.
// Note : Design an algorithm that runs better than O(n).

// Example:
// Input: Root of the below tree  
//           1
//         /   \
//        2     3
//       / \   /  \
//      4   5 6   7
// Output: 7

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
    
    // Find height by going to the left
    int leftHeight(Node* root) {
        int h = 0;
        
        while(root) {
            h++;
            root = root->left;
        }
        
        return h;
    }
    
    // Find height by going to the right
    int rightHeight(Node* root) {
        int h = 0;
        
        while(root) {
            h++;
            root = root->right;
        }
        
        return h;
    }
    
    int countNodes(Node* root) {
        
        // Empty tree
        if(root == NULL)
            return 0;
        
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        
        // If both heights are same,
        // tree is a perfect binary tree
        if(lh == rh) {
            return (1 << lh) - 1;     // OR pow(2, lh) - 1
        }
        
        // Otherwise, count root + left subtree + right subtree
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};