//Given the root of a binary tree. Find the zig-zag level order traversal of the binary tree.
// Note: In zig zag traversal we traverse the nodes from left to right for odd-numbered levels, and from right to left for even-numbered levels.

// Examples:
// Input: root = [1, 2, 3, 4, 5, 6, 7]     
// Output: [1, 3, 2, 4, 5, 6, 7]
// Explanation:
// Level 1 (left to right): [1]
// Level 2 (right to left): [3, 2]
// Level 3 (left to right): [4, 5, 6, 7]
// Final result: [1, 3, 2, 4, 5, 6, 7]

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
    vector<int> zigZagTraversal(Node* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        
        stack<Node*> s1;
        stack<Node*> s2;
        
        s1.push(root);
        while(!s1.empty()||!s2.empty()){
            while(!s1.empty()){
                Node* curr=s1.top();
                s1.pop();
            
                ans.push_back(curr->data);
                if(curr->left){
                    s2.push(curr->left);
                }
                if(curr->right){
                    s2.push(curr->right);
                }
            }
        
            while(!s2.empty()){
                Node* curr=s2.top();
                s2.pop();
            
                ans.push_back(curr->data);
                if(curr->right){
                    s1.push(curr->right);
                }
                if(curr->left){
                    s1.push(curr->left);
                }
            }
        }
        
        return ans;
    }
};