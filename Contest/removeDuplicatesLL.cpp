//Remove Duplicates from a Sorted Linked List
//Given the head of a sorted singly linked list, remove all duplicate nodes so that each element appears only once. The resulting linked list should remain sorted.
// Note: Try to solve the problem without using extra space.

// Examples:
// Input: Head: 2->2->4->5
// Output: 2 -> 4 -> 5

#include<bits/stdc++.h>
using namespace std;

// Structure of Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
      data = x;
      next = nullptr;
    }
};

class Solution {
public:
    Node* removeDuplicates(Node* head) {
        Node* curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            if (curr->data == curr->next->data) {
                curr->next = curr->next->next;
            }
            else {
                curr = curr->next;
            }
        }

        return head;
    }
};

//Approach 2 :- Using hashing

class Solution {
public:
    Node* removeDuplicates(Node* head) {
        unordered_set<int> st;

        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr) {
            // If value is already present, remove this node
            if (st.find(curr->data) != st.end()) {

                prev->next = curr->next;
                curr = curr->next;

            }
            else {
                // First time seeing this value
                st.insert(curr->data);
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};