//You a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.
// Return the nodes from the leftmost node to the rightmost node.
// If multiple nodes overlap at the same horizontal position, only the topmost (closest to the root) node is included in the view. 

// Examples:
// Input: root = [1, 2, 3]
// Output: [2, 1, 3]

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
    vector<int> topView(Node *root) {
        // If tree is empty
        if(root == nullptr)
            return {};

        unordered_map<int, int> mp; // HD -> node value
        queue<pair<Node*, int>> q;  // Store {node, horizontal distance}

        // Minimum horizontal distance
        int mn = 0;

        // Root has HD = 0
        q.push({root, 0});

        // BFS
        while(!q.empty()) {
            Node* curr = q.front().first;
            int hd = q.front().second;
            q.pop();

            // Update minimum HD
            mn = min(mn, hd);

            // First node at this HD
            if(mp.find(hd) == mp.end()) {
                mp[hd] = curr->data;
            }

            // Left child -> HD - 1
            if(curr->left) {
                q.push({curr->left, hd - 1});
            }

            // Right child -> HD + 1
            if(curr->right) {
                q.push({curr->right, hd + 1});
            }
        }

        // Number of different horizontal distances
        vector<int> ans(mp.size());

        // Put values from left to right (Convert HD into left-to-right index)
        for(auto it = mp.begin(); it != mp.end(); it++) {
            int hd = it->first;
            int value = it->second;

            ans[hd - mn] = value;
        }

        return ans;
    }
};