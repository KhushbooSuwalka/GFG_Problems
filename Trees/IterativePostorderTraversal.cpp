//Given a binary tree root[]. Find the postorder traversal of the tree without using recursion. Return a list containing the postorder traversal of the tree, calculated without using recursion.

// Examples :
// Input: root[] = [1, 2, 3, 4, 5]
// Output: [4, 5, 2, 3, 1]

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

// Approach 1 :- Using two stacks

vector<int> postOrder(Node* root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }

    // Create two stacks
    stack<Node*> stk1, stk2;

    // Push root to first stack
    stk1.push(root);
    Node* curr;

    // Run while first stack is not empty
    while (!stk1.empty()) {
      
        // Pop from s1 and push it to s2
        curr = stk1.top();
        stk1.pop();
        stk2.push(curr);

        // Push left and right children of the popped node
        if (curr->left) {
            stk1.push(curr->left);
        }
        if (curr->right) {
            stk1.push(curr->right);
        }
    }

    // Collect all elements from second stack
    while (!stk2.empty()) {
        curr = stk2.top();
        stk2.pop();
        result.push_back(curr->data);
    }

    return result;
}

// Approach 2 :- Using one stack

vector<int> postOrder(Node* root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }

    stack<Node*> stk;

    while (root != nullptr || !stk.empty()) {

        // Move to the leftmost node and push right child and root
        while (root != nullptr) {
            if (root->right != nullptr) {
                stk.push(root->right);
            }
            stk.push(root);
            root = root->left;
        }

        // Step 2: Pop an item from the stack
        root = stk.top();
        stk.pop();

        // Step 2a: If the popped node has a right child and the right child is on the top of the stack
        if (!stk.empty() && root->right != nullptr && stk.top() == root->right) {
            stk.pop();  
            stk.push(root);  
            root = root->right; 
        } 
        else {
            // Step 2b: Else, print the node's data and set root as null
            result.push_back(root->data);
            root = nullptr;
        }
    }

    return result;
}