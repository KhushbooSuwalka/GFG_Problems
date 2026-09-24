//Given a Binary Search Tree(BST) and a target. Check whether there's a pair of Nodes in the BST with value summing up to the target. 

// Examples:
// Input: root[] = [7, 3, 8, 2, 4, N, 9], target = 12
// Output: True
// Explanation: In the binary tree above, there are two nodes (8 and 4) that add up to 12.

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

// Approach :- Inorder + Two Pointers

class Solution {
  public:
    void inorder(Node* root, vector<int>& arr) {
        if(root == NULL)  return;
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
        
    bool findTarget(Node *root, int target) {
        vector<int> ans; //Stores inorder traversal
        inorder(root,ans);
        
        int left = 0;
        int right = ans.size()-1;
        
        while(left < right){
            int sum = ans[left] + ans[right];
            
            if(sum == target){
                return true;
            } else if (sum > target){
                right--;
            } else {
                left++;
            }
        }
        
        return false;
    }
};