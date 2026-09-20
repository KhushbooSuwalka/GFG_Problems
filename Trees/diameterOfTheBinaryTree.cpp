//Given the root of a binary tree, find the diameter of the binary tree. The diameter of a binary tree is defined as the number of edges on the longest path between any two nodes. Note that this path may or may not pass through the root of the tree.

// Examples:
// Input: root = [5, 8, 6, 3, 7, 9, N]
// Output: 4
// Explanation: The longest path has 4 edges (node 3 -> node 8 -> node 5 -> node 6 -> node 9).

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
    int solve(Node* root , int &ans){
        if(!root){
            return 0;
        }
        
        int left = solve(root->left,ans);
        int right = solve(root->right,ans);
        
        // The heighest diameter store in this ans from ans and current node se banne wala diameter 
        ans = max(ans,left+right);
        
        // Current node ki height return kro 
        return 1 + max(left,right);
    }
    
    int diameter(Node* root) {
        int ans=0;
        solve(root ,ans);
        return ans;
    }
};