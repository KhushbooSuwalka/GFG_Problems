//Given the root of a binary tree, the value of a target node, and an integer k, return all the nodes that are exactly k edges away from the target node. Return the node values in sorted order.
// Note:
// The tree does not contain parent pointers.
// All node values are unique.
// The target node is guaranteed to be present in the tree.

// Examples:
// Input: root = [1, 2, 3, 4, 5], target = 2, k = 2   
// Output: [3]
// Explanation: Nodes at a distance 2 from the given node 2 is 3.

#include <bits/stdc++.h>
using namespace std;

class Node {
public: 
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Approach 1 :- Using BFS and HashMap to store parent pointers

class Solution {
public:
    vector<int> kDistanceNodes(Node* root, int target, int k) {
        unordered_map<Node*, Node*> parent;
        queue<Node*> q;

        // Find parent of every node
        q.push(root);
        parent[root] = NULL;

        Node* targetNode = NULL;

        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if(curr->data == target)
                targetNode = curr;

            if(curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }

            if(curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }

        // BFS from target
        vector<int> ans;
        unordered_map<Node*, bool> visited;

        q.push(targetNode);
        visited[targetNode] = true;

        int level = 0;
        while(!q.empty()) {
            int n = q.size();
            if(level == k) {
                while(!q.empty()) {
                    ans.push_back(q.front()->data);
                    q.pop();
                }
                break;
            }

            while(n--) {
                Node* curr = q.front();
                q.pop();

                if(curr->left && !visited[curr->left]) {
                    visited[curr->left] = true;
                    q.push(curr->left);
                }

                if(curr->right && !visited[curr->right]) {
                    visited[curr->right] = true;
                    q.push(curr->right);
                }

                if(parent[curr] && !visited[parent[curr]]) {
                    visited[parent[curr]] = true;
                    q.push(parent[curr]);
                }
            }

            level++;
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};