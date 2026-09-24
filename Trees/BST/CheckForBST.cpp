//Given a binary tree, check whether it is a Binary Search Tree (BST) or not. A binary tree is considered a BST if it satisfies the following properties:
// 1. All nodes in the left subtree of a node have values less than the node's value.
// 2. All nodes in the right subtree of a node have values greater than the node's value.
// 3. Both the left and right subtrees are also Binary Search Trees.
// Return true if the given binary tree is a BST; otherwise, return false.

// Examples:
// Input: root = [2, 1, 3, N, N, N, 5]
// Output: true 

#include<bits/stdc++.h>
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

//Approach 1:- By Recursion

class Solution {
  public:
    // Recursive Function for inorder traversal
    bool solve(Node* root,int &prev){
        if(!root) return true;
       
        // Recursively check the left subtree
	    if (!solve(root->left, prev)) 
	      	return false;
	      	
	    // Check the current node value against the previous value
        if(prev >= root->data){
           return false;
        }
       
        prev = root->data;
       
       
        // Recursively check the right subtree
        return solve(root->right,prev);
    }
    
    bool isBST(Node* root) {
        int prev = INT_MIN;
        return solve(root,prev);
    }
};

//Approach 2 :- By Morris Traversal

// Function to check if the binary tree is a BST using Morris Traversal
bool isBST(Node* root) {
    Node* curr = root;
    Node* pre = nullptr;
    int prevValue = INT_MIN; 

    while (curr != nullptr) {
        if (curr->left == nullptr) {
            if (curr->data <= prevValue) {
                // Not in ascending order
                return false; 
            }
            prevValue = curr->data;
            curr = curr->right;
        } 
        
        else { 
            // Find the inorder predecessor of curr
            pre = curr->left;
            while (pre->right != nullptr && pre->right != curr) {
                pre = pre->right;
            }

            if (pre->right == nullptr) {
                // Create a temporary thread to the curr node
                pre->right = curr;
                curr = curr->left;
            } 
            
            else {  
                pre->right = nullptr;

                if (curr->data <= prevValue) {
                    // Not in ascending order
                    return false; 
                }
                prevValue = curr->data;
                curr = curr->right;
            }
        }
    }

    return true; 
}