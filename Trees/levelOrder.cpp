//Given the root of a Binary Tree, your task is to return its Level Order Traversal.
// Note: A level order traversal is a breadth-first search (BFS) of the tree. It visits nodes level by level, starting from the root, and processes all nodes from left to right within each level before moving to the next.

// Examples:
// Input: root = [1, 2, 3]
// Output: [1, 2, 3]
// Explanation: We start with the root node 1, so the first level of the traversal is [1]. Then we move to its children 2 and 3, which form the next level, giving the final output [1, 2, 3].

#include <bits/stdc++.h>
using namespace std;

class Node {
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
    vector<int> levelOrder(Node* root) {
        vector<int>  result;
        if (!root) return result;

        queue<Node*> q;
        q.push(root); // Start BFS from the root node

        while (!q.empty()) {   
            Node* curr = q.front();
            q.pop();                // Remove the front node from the queue

            result.push_back(curr->data);

            if(curr->left) {
                q.push(curr->left); // Add left child to the queue
            }

            if(curr->right) {
                q.push(curr->right); // Add right child to the queue
            }

        }

        return result; // Return the final level order traversal
    }
};