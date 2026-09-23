#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public: 
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if (root == nullptr)
            return ans;                         // Empty tree

        queue<TreeNode*> q;
        q.push(root);                           // Start BFS from root

        while (!q.empty()) {

            int n = q.size();                   // Number of nodes in current level
            vector<int> level;

            for (int i = 0; i < n; i++) {

                TreeNode* curr = q.front();
                q.pop();

                level.push_back(curr->val);     // Add current node to level

                if (curr->left)
                    q.push(curr->left);         // Add left child

                if (curr->right)
                    q.push(curr->right);        // Add right child
            }

            ans.push_back(level);               // Store completed level
        }

        return ans;
    }
};