//Given a Binary Tree of size n, You have to count leaves in it.

#include <bits/stdc++.h>
using namespace std;

// A binary tree node has data, pointer to left child and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; 

// Class Solution
class Solution {
  public:
    int solve(Node* root){
        if(root == NULL){
            return 0;
        }
        
        //Leaf Node found
        if(root->left == NULL && root->right == NULL){
            return 1;
        }
        
        //Recursively count left and right leaves 
        int left = solve(root->left);
        int right = solve(root->right);
        
        return left + right;
    }
    
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        return solve(root);
    }
};