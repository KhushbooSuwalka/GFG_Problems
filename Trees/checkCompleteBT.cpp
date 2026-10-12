//Given a Binary Tree, check whether the given Binary Tree is Complete Binary Tree or not. A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes should be as much close to left as possible.

// Examples:
// Input: root = [1, 2, 3]
// Output: true
// Explanation: The given tree is complete binary tree.

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
    bool isCompleteBT(Node* root) { 
        if (root == NULL)
            return true;
        
        queue<Node*> q;
        q.push(root);
        
        bool nullFound = false;
        
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            // If current node is NULL
            if (curr == NULL) {
                nullFound = true;
            } else {
                // NULL already mil chuka hai, aur ab non-NULL node mili
                if (nullFound)
                    return false;
                
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        
        return true;
    }
};