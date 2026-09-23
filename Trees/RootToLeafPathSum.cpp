//Given root of a binary tree and an integer target, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum. Return false if no such path can be found. 

// Examples :
// Input: root = [1, 2, 3], target = 4
// Output: true
// Explanation: The root to leaf path sums are 1 + 2 = 3 and 1 + 3 = 4. Since, a path with sum 4 exists (1 -> 3), the answer is true.

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
    bool hasPathSum(Node *root, int target) {
        if(root == NULL){
            return false;
        }
        
        target -= root->data;
        
        //Check sum Only at a leaf
        if(root->left == NULL && root->right == NULL){
            return target==0;
        }
        
        return hasPathSum(root->left,target) || hasPathSum(root->right,target);
    }
};