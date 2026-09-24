//Given the root of a binary tree and a target node, determine the minimum time required to burn the entire tree if the target node is set on fire. In one second, the fire spreads from a node to its left child, right child, and parent.
// Note: The tree contains unique values.

// Examples : 
// Input: root = [1, 2, 3, 4, 5, 6, 7], target = 2
// Output: 3
// Explanation: Initially 2 is set to fire at 0 sec 
// At 1 sec: Nodes 4, 5, 1 catches fire.
// At 2 sec: Node 3 catches fire.
// At 3 sec: Nodes 6, 7 catches fire.
// It takes 3s to burn the complete tree.

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
    // Step 1: Store parent of every node
    void markParent(Node* root, unordered_map<Node*, Node*> &parent) {
        queue<Node*> q;
        q.push(root);

        parent[root] = NULL;

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }

            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    // Find target node
    Node* findTarget(Node* root, int target) {
        if (root == NULL)
            return NULL;

        if (root->data == target)
            return root;

        Node* left = findTarget(root->left, target);

        if (left != NULL)
            return left;

        return findTarget(root->right, target);
    }

    int minTime(Node* root, int target) {
        // Step 1 :- Store parent pointers
        unordered_map<Node*,Node*> parent;
        markParent(root,parent);
        
        // Step 2 :- Find target node
        Node* targetNode = findTarget(root,target);
        
        // Step 3 :- BFS from target
        queue<Node*> q;
        unordered_map<Node*,bool> visited;
        
        q.push(targetNode);
        visited[targetNode] = true;
        
        int time = 0;
        
        while (!q.empty()) {
            int size = q.size();
            bool burned = false;

            // Process one second
            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();

                // Fire goes to left child
                if (curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                    burned = true;
                }

                // Fire goes to right child
                if (curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                    burned = true;
                }

                // Fire goes to parent
                if (parent[curr] && !visited[parent[curr]]) {
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                    burned = true;
                }
            }

            // If fire reached at least one new node, one second has passed
            if (burned)
                time++;
        }
        
        return time;
    }
};