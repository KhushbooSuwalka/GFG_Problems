//Given a binary tree with n nodes and two node values a and b, find the minimum distance between them. The distance is defined as the minimum number of edges between the two nodes. It is guaranteed that both nodes exist in the binary tree and all node values are unique.

// Examples :
// Input: [1,2,3,4,5,6,7], a = 4, b = 7
// Output: 4
// Explanation: The path between node 4 and node 7 is: 4 -> 2 -> 1 -> 3 -> 7.The number of edges in this path is 4, so the minimum distance is 4.

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

// Distance(a, b) = distance from LCA to a + distance from LCA to b.

class Solution {
  public:
    // Find the LCA of a and b
    Node* findLCA(Node* root, int a, int b) {
        if (root == NULL)
            return NULL;

        // If current node is a or b
        if (root->data == a || root->data == b)
            return root;

        Node* left = findLCA(root->left, a, b);
        Node* right = findLCA(root->right, a, b);

        // a and b are present in different sides
        if (left != NULL && right != NULL)
            return root;

        // If only left side has one of them
        if (left != NULL)
            return left;

        // Otherwise return right
        return right;
    }

    // Find distance from root to a node
    int findDistance(Node* root, int target) {
        if (root == NULL)
            return -1;

        // Target found
        if (root->data == target)
            return 0;

        // Search in left subtree
        int left = findDistance(root->left, target);

        if (left != -1)
            return left + 1;

        // Search in right subtree
        int right = findDistance(root->right, target);

        if (right != -1)
            return right + 1;

        return -1;
    }

    int findDist(Node* root, int a, int b) {
        // Step 1: Find LCA
        Node* lca = findLCA(root, a, b);

        // Step 2: Distance from LCA to a
        int d1 = findDistance(lca, a);

        // Step 3: Distance from LCA to b
        int d2 = findDistance(lca, b);

        // Step 4: Total distance
        return d1 + d2;
    }
};