//Given the root of a binary tree. Return the left view of the binary tree. The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.
// Note: If the tree is empty, return an empty list.

// Examples :
// Input: root = [1, 2, 3, 4, 5, N, N] 
// Output:[1, 2, 4]

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

//Approach 1 :- Using BFS(Level Order Traversal)

class Solution {
  public:
    vector<int> leftView(Node *root) {
        vector<int> ans;
        
        if(root == NULL)
            return ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            
            // First node of every level
            ans.push_back(q.front()->data);

            for(int i = 0; i < n; i++) {
                Node* curr = q.front();
                q.pop();
                
                // Enqueue left child
                if(curr->left != NULL) {
                    q.push(curr->left); 
                }
                
                // Enqueue right child
                if(curr->right != NULL) {
                    q.push(curr->right);
                }
            }
        }
        
        return ans;
    }
};

//Approach 2 :- Using DFS(Preorder Traversal)

class Solution {
  public:
    void solve(Node* root, int level, vector<int>& ans) {
        if(root == NULL)
            return;
        
        // If this is the first node of the current level
        if(level == ans.size()) {
            ans.push_back(root->data);
        }
        
        // Go left first, then right for left view
        solve(root->left, level + 1, ans);
        solve(root->right, level + 1, ans);
    }
    
    vector<int> leftView(Node *root) {
        vector<int> ans;
        solve(root, 0, ans);
        return ans;
    }
};