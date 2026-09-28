//Given root of a binary tree and the values of its two nodes p and q, count turns required to travel from node p to q.
// A turn occurs whenever the direction of movement changes from left to right or right to left while traversing the tree.
// If the path between the two nodes does not involve any turns (i.e., the nodes lie on the same straight path), return -1.
// Note: All node values are distinct.

// Examples :
// Input: root[] = [1, 2, 3, 4, 5, 6, 7, 8, N, N, N, 9, 10], p = 5, q = 10
// Output: 4
// Explanation: The path from node 5 to node 10 is: 5 -> 2 -> 1 -> 3 -> 6 → 10. Direction changes occur at nodes 2, 1, 3, and 6. Therefore, the number of turns is 4.

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

// Idea:
// 1. Root se p tak ka path nikalo.
// 2. Root se q tak ka path nikalo.
// 3. Dono paths ko compare karke LCA tak pahucho.
// 4. p → LCA → q ke path mein direction L/R dekho.
// 5. Jab L → R ya R → L ho, ek turn count karo.
// 6. Agar ek bhi turn nahi hai, answer -1.

class Solution {
public:  
    bool findPath(Node* root, int value, vector<char>& path) {
        if (root == NULL)
            return false;

        if (root->data == value)
            return true;

        // Go left
        path.push_back('L');

        if (findPath(root->left, value, path))
            return true;

        path.pop_back();

        // Go right
        path.push_back('R');

        if (findPath(root->right, value, path))
            return true;

        path.pop_back();

        return false;
    }

    int numberOfTurns(Node* root, int p, int q) {
        vector<char> pathP, pathQ;

        findPath(root, p, pathP);
        findPath(root, q, pathQ);

        // Find common path till LCA
        int i = 0;
        while (i < pathP.size() && i < pathQ.size() && pathP[i] == pathQ[i]) {
            i++;
        }

        vector<char> path;

        // p -> LCA
        for (int j = pathP.size() - 1; j >= i; j--) {
            path.push_back(pathP[j]);
        }

        // LCA -> q
        for (int j = i; j < pathQ.size(); j++) {
            path.push_back(pathQ[j]);
        }

        int turns = 0;

        for (int j = 1; j < path.size(); j++) {
            if (path[j] != path[j - 1])
                turns++;
        }

        if (turns == 0) return -1; 
        return turns;
    }
};