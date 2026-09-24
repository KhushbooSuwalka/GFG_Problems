//Inorder Traversal
//Given the root of a binary tree, Find its inorder traversal using Morris Traversal, i.e., without using recursion or a stack.

#include <bits/stdc++.h>
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
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        Node* curr = root;
        
        while(curr){
            // If no left child, visit this node and go right
            if(curr->left == NULL){
                ans.push_back(curr->data);
                curr = curr->right;
            }
            
            else{
                //Find predecessor
                Node* pre = curr->left;
            
                while(pre->right != NULL && pre->right != curr){
                    pre = pre->right;
                }
            
                // No thread? → Create thread + go left
                if(pre->right == NULL){
                    pre->right = curr;
                    curr = curr->left;
                }
                
                // Thread exists? → Remove thread + process + go right
                else{
                    pre->right = NULL;
                    ans.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
        
        return ans;
    }
};