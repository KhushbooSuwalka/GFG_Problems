//Given a Binary Search Tree, convert it into a Special Max Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied on all the nodes in the so converted Max Heap.

// Examples:
// Input: root[] = [4, 2, 6, 1, 3, 5, 7]
// Output: [1, 2, 3, 4, 5, 6, 7] 

#include<bits/stdc++.h>
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
    vector<int> values;
    int index;

    // Step 1: Inorder se sorted values nikalo
    void inorder(Node* root) {
        if(root == NULL)
            return;

        inorder(root->left);

        values.push_back(root->data);

        inorder(root->right);
    }

    // Step 2: Postorder mein values assign karo
    void postorder(Node* root) {
        if(root == NULL)
            return;

        postorder(root->left);
        postorder(root->right);

        root->data = values[index];
        index++;
    }

    void convertToMaxHeap(Node* root) {
        values.clear();
        index = 0;

        inorder(root);
        postorder(root);
    }
};