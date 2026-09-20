//Given the root of a binary tree, find if the tree contains any duplicate subtree of size two or more. Two subtrees are considered duplicates if they have the same structure and identical node values.
// Note: Subtrees consisting of only a single leaf node are not considered duplicate subtrees.

// Examples :
// Input : root = [1, 2, 3] 
// Output: false
// Explanation: There is no duplicate sub-tree in the given binary tree.

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

class Solution {
public:
    string solve(Node* root, unordered_map<string, int>& mp, bool& found) {
        if(root == NULL)
            return "#";

        string left = solve(root->left, mp, found);
        string right = solve(root->right, mp, found);

        // Make string of current subtree
        string curr = to_string(root->data) + "," + left + "," + right;

        // Only check subtree of size 2 or more
        if(root->left != NULL || root->right != NULL) {
            mp[curr]++;
            if(mp[curr] >= 2)
                found = true;
        }

        return curr;
    }

    bool dupSub(Node* root) {
        unordered_map<string, int> mp;
        bool found = false;

        solve(root, mp, found);
        return found;
    }
};