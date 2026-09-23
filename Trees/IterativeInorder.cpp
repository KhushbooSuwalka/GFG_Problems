//Given a binary tree. Find the inorder traversal of the tree without using recursion.

// Example:
// Input : [1, 2, 3, 4, 5]
// Output: 4 2 5 1 3
// Explanation: Inorder traversal (Left->Root->Right) of the tree is [4, 2, 5, 1, 3].

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
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        stack<Node*> st;
        Node* curr = root;
        
        while(curr != NULL || !st.empty()){
            //Keep going left and store nodes in stack
            while(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }

            //Left subtree is done, now process the root
            curr = st.top();
            st.pop();
            ans.push_back(curr->data); //Visit node
            curr = curr->right; //Now, process the right subtree
        }
        
        return ans;
    }
};