//Given the roots r1 and r2 of two Binary Search Trees (BSTs), merge the elements of both trees into a single sorted array and return it.
// The returned array should contain all the elements from both BSTs, including duplicate values if they are present.

// Examples: 
// Input: r1 = [3, 1, 5], r2 = [4, 2, 6]
// Output: [1, 2, 3, 4, 5, 6]

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

void inorder(Node* root, vector<int>& arr) {
    if (!root) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

// Function to merge two sorted arrays into one sorted array
vector<int> mergeArrays(vector<int>& arr1, vector<int>& arr2) {
    vector<int> result;
    int i = 0, j = 0;
    
    // Traverse both arrays and pick the smaller element
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] <= arr2[j]) {
            result.push_back(arr1[i++]);
        } 
        else {
            result.push_back(arr2[j++]);
        }
    }
    
    while (i < arr1.size()) result.push_back(arr1[i++]); 
    while (j < arr2.size()) result.push_back(arr2[j++]);
    
    return result;
}

// Function to merge elements of two BSTs into a single sorted list
vector<int> merge(Node *root1, Node *root2) {
    vector<int> arr1, arr2;
    
    // Get inorder traversal of both BSTs
    inorder(root1, arr1);
    inorder(root2, arr2);
    
    return mergeArrays(arr1, arr2);
}
