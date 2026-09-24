//Given the root of a Binary Search Tree (BST) and an integer k, find the k-th largest element in the BST without modifying its structure.

// Examples:
// Input: root = [4, 2, 9], k = 2
// Output: 4
// Explanation: The second largest element is 4.

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

// Approach 1 :- Using Recursion

class Solution {
  public:
    int solve(Node* root,int &count,int k){
        if(!root) return -1;

        int right = solve(root->right,count,k);

        // if kth largest number is present in right subtree, then return it.
        if (right != -1) return right;

        count++;
        // If curr node is kth largest,return it
        if(count == k){
            return root->data;
        }

        int left = solve(root->left, count, k);
        return left;
    }
    
    int kthLargest(Node *root, int k) {
        int count = 0;
        return solve(root,count,k);
        
    }
};

// Approach 2 :- Using Morris Traversal Algorithm 

class Solution {
  public:
    int solve(Node* root,int &count,int k){
        Node* curr = root;

        while(curr){
            if(curr->right == NULL){
                count++;
                if(count==k) return curr->data;
                curr = curr->left;
            } else {

                // Find the inorder successor of the current node
                Node* succ = curr->right;

                while(succ->left && succ->left != curr){
                    succ = succ->left;
                }

                // Create a temporary thread to the current node
                if(!succ->left){  
                    succ->left = curr;
                    curr = curr->right;
                }

                else{    
                    // Remove the temporary thread
                    succ->left = NULL;
                    count++;
                    if(count==k) return curr->data;
                    curr = curr->left;
                }
            }
        }
        
        // Return -1 if k is greater than the number of nodes
        return -1;
    }
    
    int kthLargest(Node *root, int k) {
        int count = 0;
        return solve(root,count,k);

    }
};