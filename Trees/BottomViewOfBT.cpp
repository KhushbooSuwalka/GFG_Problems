//You are given the root of a binary tree, and your task is to return its bottom view. The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom.
// Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level order traversal is considered.

// Examples :
// Input: root = [20, 8, 22, 5, 3, 4, 25, N, N, 10, 14, N, N, 28, N]
// Output: [5, 10, 4, 28, 25]

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

// using BFS (level order traversal) + horizontal distance.

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        
        if(root == NULL)
            return ans;
        
        // horizontal distance -> node value
        map<int, int> mp;
        
        // pair = {node, horizontal distance}
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        
        while(!q.empty()) {
            Node* curr = q.front().first;
            int hd = q.front().second;
            q.pop();
            
            // Latest node at this horizontal distance becomes bottom view
            mp[hd] = curr->data;
            
            // Left child
            if(curr->left != NULL) {
                q.push({curr->left, hd - 1});
            }
            
            // Right child
            if(curr->right != NULL) {
                q.push({curr->right, hd + 1});
            }
        }
        
        // map automatically gives hd from smallest to largest (Convert HD into left-to-right index)
        for(auto x : mp) {
            ans.push_back(x.second);
        }
        
        return ans;
    }
};