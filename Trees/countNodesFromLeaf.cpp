//Count Nodes at Distance K From Leaf
// Given a binary tree with n nodes and a non-negative integer k, the task is to count the number of special nodes.
// A node is considered special if there exists at least one leaf in its subtree such that the distance between the node and leaf is exactly k.
// Any such node should be counted only once. For example, if a node is at a distance k from 2 or more leaf nodes, then it would add only 1 to the count.

// Examples:
// Input: root[] = [1, 2, 3, 4, 5, 6, 7, N, N, N, N, N, 8], k = 2            
// Output: 2
// Explanation: There are only two unique nodes that are at a distance of 2 units from the leaf node. (node 3 for leaf with value 8 and node 1 for leaves with values 4, 5 and 7) Note that node 2 isn't considered for leaf with value 8 because it isn't a direct ancestor of node 8.

#include <bits/stdc++.h>
using namespace std;

// Using DFS + a path vector (Path Level Marking)

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

class Solution {
  public:
    void solve(Node* root, int k, vector<Node*>& path, unordered_set<Node*>& visited, int& ans) {
        if(root == NULL)
            return;

        // Put current node in path
        path.push_back(root);

        // If current node is a leaf
        if(root->left == NULL && root->right == NULL) {

            // Check if k-th ancestor exists
            if(path.size() > k) {
                Node* temp = path[path.size() - k - 1];

                // Count only once
                if(visited.find(temp) == visited.end()) {
                    visited.insert(temp);
                    ans++;
                }
            }
        }

        // Go left and right
        solve(root->left, k, path, visited, ans);
        solve(root->right, k, path, visited, ans);

        // Remove current node while returning
        path.pop_back();
    }

    int kthFromLeaf(Node* root, int k) {
        vector<Node*> path;
        unordered_set<Node*> visited;

        int ans = 0;
        solve(root, k, path, visited, ans);

        return ans;
    }
};