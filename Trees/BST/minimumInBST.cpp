//Given the root of a Binary Search Tree, find the minimum element in this given BST.

// Examples
// Input: root = [5, 4, 6, 3, N, N, 7, 1]
// Output: 1
// Explanation: The minimum element in the given BST is 1.

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
    int minValue(Node* root) {
        while(root->left){
            root = root->left;
        }
        
        return root->data;
    }
};

// Approach 2 :- Recursive Approach

class Solution {
  public:
    int minValue(Node* root) {
        if(root->left == NULL){
            return root->data;
        }
        
        minValue(root->left);
    }
};