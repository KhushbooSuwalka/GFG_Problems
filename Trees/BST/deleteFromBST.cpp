//Given a binary search tree and a node value x. Delete the node with the given value x from the tree. If no node with value x exists, then do not make any change. 
// Return the root of the tree after deleting the node with value x.
// Note: You may return any valid BST after deleting the specified node. The driver code will print true if the resulting tree is a valid BST after deletion, and false otherwise.

// Examples :
// Input: root = [2, 1, 3], x = 12
// Output: true
// Explanation: In the given input there is no node with value 12, so the tree will remain same.

#include <bits/stdc++.h>
using namespace std;

class Node {
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

// Inorder successor :- Current node ke right subtree ki sabse chhoti value find karna.

class Solution {
  public:
    // Get inorder successor (smallest in right subtree)
    Node* getSuccessor(Node* curr) {
        curr = curr->right;
        
        while (curr != nullptr && curr->left != nullptr)
            curr = curr->left;
            
        return curr;
    }
    
    Node* delNode(Node* root, int x) {
        if(root==NULL)  return root;
        
        if(root->data > x){
            root->left = delNode(root->left,x);
        }
        
        else if(root->data < x){
            root->right = delNode(root->right,x);
        }
        
        else{
            // Node with 0 or 1 child
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            
            if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Node with 2 children
            Node* succ = getSuccessor(root);
            root->data = succ->data;
            root->right = delNode(root->right, succ->data);
        }
        
        return root;
    }
};