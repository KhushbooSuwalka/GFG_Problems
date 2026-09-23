//Given a Binary Search Tree (BST) and an integer key, find the inorder predecessor and inorder successor of the given key.
// The inorder predecessor is the node with the largest value smaller than the given key.
// The inorder successor is the node with the smallest value greater than the given key.
// If the predecessor or successor does not exist, return NULL for that position.
// Note: The key may or may not be present in the BST.

// Examples :
// Input: root = [50, 30, 70, 20, 40, 60, 80], key = 65
// Output: [60, 70]

#include <bits/stdc++.h>
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
    Node* Predecessor(Node* root,int key){
        Node* pre = NULL;
        
        while(root){
            if(key > root->data){
                pre = root;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        
        return pre;
    }
    
    Node* Successor(Node* root,int key){
        Node* succ = NULL;
        
        while(root){
            if(key < root->data){
                succ = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        
        return succ;
    }
    
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = Predecessor(root,key);
        Node* succ = Successor(root,key);
        return {pre,succ};
    }
};