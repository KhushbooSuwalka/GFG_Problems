//Given the root of a Binary Tree, find the maximum and minimum element present in the tree.

// Examples:
// Input: root[] = [2, 7, 5, N, 6, N, 9, 1, 11, 4]
// Output: 11 1

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

class Solution {
  public:
    void solveMax(Node* root,int& maxi){
        if(root==NULL) return;
        maxi = max(maxi,root->data);
        solveMax(root->left,maxi);
        solveMax(root->right,maxi);
    }
    
    int findMax(Node *root) {
        int maxi=INT_MIN;
        solveMax(root,maxi);
        return maxi;
    }
    
    void solveMin(Node* root,int& mini){
        if(root==NULL) return;
        mini = min(mini,root->data);
        solveMin(root->left,mini);
        solveMin(root->right,mini);
    }

    int findMin(Node *root) {
        int mini=INT_MAX;
        solveMin(root,mini);
        return mini;
    }
};