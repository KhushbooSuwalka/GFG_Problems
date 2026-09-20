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
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        // current node + both left and right subtrees
        return 1 + left + right;
    }
    
    int countNodes(Node* root) {
        return solve(root);
    }
};