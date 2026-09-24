//Given the root of a BST and an integer k, find the kth smallest element in the BST. If there is no kth smallest element present then return -1.

// Examples:
// Input: root = [20, 8, 22, 4, 12, N, N, N, N, 10, 14], k = 3 
// Output: 10

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

// Approach 1 :- By inorder traversal

class Solution {
  public:
    int solve(Node* root,int &count,int k){
        if(!root) return -1;
        
        int left = solve(root->left,count,k);
        
        // If kth smallest is found in left subtree, then return it
        if (left != -1) return left;
        
        count++;
        // If curr node is kth smallest,return it
        if(count == k){
            return root->data;
        }
        
        int right = solve(root->right, count, k);
        return right;
    }
    
    int kthSmallest(Node *root, int k) {
        int count = 0;
        return solve(root,count,k);
    }
};

// Approach 2 :-  By Morris Inorder Traversal

class Solution {
  public:
    int solve(Node* root,int &count,int k){
        Node* curr = root;
        
        while(curr){
            if(curr->left == NULL){
                count++;
                if(count==k) return curr->data;
                curr = curr->right;
            } else {
                
                // Find the inorder predecessor of curr
                Node* pre = curr->left;
                
                while(pre->right && pre->right != curr){
                    pre = pre->right;
                }
                
                // Make curr the right child of its inorder predecessor
                if(!pre->right){  
                    pre->right = curr;
                    curr = curr->left;
                }
                
                else{    // Revert the changes made in the tree structure
                    pre->right = NULL;
                    count++;
                    if(count==k) return curr->data;
                    curr = curr->right;
                }
            }
        }
        
        return -1;
    }
    
    int kthSmallest(Node *root, int k) {
        int count = 0;
        return solve(root,count,k);
    }
};