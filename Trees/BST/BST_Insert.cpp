//Given a root of Binary Search Tree (BST) and an integer key, insert a new node with value key into the BST. Return the root of the modified tree after the insertion.
// Note: If the key is already present in the BST, return the root.

// Examples :
// Input: root = [2, 1, 3], key = 4
// Output: [2, 1, 3, N, N, N, 4]

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

// Approach 1 :- Recursive Approach

class Solution {
  public:
    Node* insert(Node* root, int key) {
        //Insert node at an empty position
        if(root==NULL){
            return new Node(key);
        }
        
        //Key is already present,not insert again
        if(root->data == key){
            return root;
        }
        
        //Insert in right subtree
        if(root->data < key){
            root->right = insert(root->right,key);
        } 
        
        //Insert in left subtree
        else {
            root->left = insert(root->left,key);
        }
        
        return root;
    }
};

// Approach 2 :- Iterative Approach

class Solution {
  public:
    Node* insert(Node* root, int key) {
        if(root==NULL){
            return new Node(key);
        }
        
        Node* prev = NULL;
        Node* curr = root;
        
        while(curr){
            prev = curr;
            
            if(curr->data == key){
                return root;
            }
            
            if(key > curr->data){
                curr = curr->right;
            }else{
                curr = curr->left;
            }
        }
        
        if(key > prev->data){
            prev->right = new Node(key);
        } else {
            prev->left = new Node(key);
        }
        
        return root;
    }
};

// Approach 3 :- Iterative Approach

class Solution {
  public:
    Node* insert(Node* root, int key) {
        if(root==NULL){
            return new Node(key);
        }
        
        Node* curr = root;
        
        while(true){
            if(curr->data == key){
                return root;
            }
            
            if(key > curr->data){
                if(!curr->right){
                    curr->right = new Node(key);
                    break;
                }
                curr = curr->right;
            }
            
            else{
                if(!curr->left){
                    curr->left = new Node(key);
                    break;
                }
                curr = curr->left;
            }
        }
        
        return root;
    }
};