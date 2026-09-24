//Given a Binary tree. Find the preorder traversal of the tree without using recursion.
// Follow up: Try solving this with O(1) auxiliary space.

// Examples:
// Input: root[] = [1, 2, 3, 4, 5]
// Output: [1, 2, 4, 5, 3]

#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    vector<int> preOrder(Node* root) {
        vector<int> ans;
        if(!root) return ans;
        
        stack<Node*> s;
        s.push(root);
        
        while(!s.empty()){
           Node* curr = s.top();
           s.pop();
           
           ans.push_back(curr->data);
           
           if(curr->right){
               s.push(curr->right);
           }
           
           if(curr->left){
               s.push(curr->left);
           }
        }
        
        return ans;
    }
};