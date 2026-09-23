//Given a Binary Search Tree and a node value key, return true if the node with value key is present in the BST; otherwise, return false.

// Examples:
// Input: root = [6, 2, 8, N, N, 7, 9], key = 8   
// Output: true
// Explanation: 8 is present in the BST as right child of root.

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

// Approach 1 :- Iterative Approach

class Solution {
  public:
    bool search(Node* root, int key) {
        while(root!=NULL){
            if(root->data == key){
               return true;
            } else if (root->data < key){
                root = root->right;
            } else{
                root = root->left;
            }
        }
        
        return false;
    }
};

// Approach 2 :- Recursive Approach

class Solution {
  public:
    bool search(Node* root, int key) {
        if(root==NULL){
            return false;
        }
        
        if(root->data == key){
            return true;
        }
        
        if(key > root->data){
            search(root->right,key);
        } else {
            search(root->left,key);
        }
    }
};