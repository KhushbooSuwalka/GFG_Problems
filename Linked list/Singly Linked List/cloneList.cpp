//Clone List with Next and Random
//Given a special linked list with n nodes where each node has two pointers a next pointer that points to the next node of the singly linked list, and a random pointer that points to the random node of the linked list.
// 1. Construct a copy of this linked list. The copy should consist of the same number of new nodes, where each new node has the value corresponding to its original node.
// 2. Both the next and random pointer of the new nodes should point to new nodes in the copied list, such that it also represent the same list structure.
// 3. None of the pointers in the new list should point to nodes in the original list and original linked list should remain unchanged.
// Return the head of the copied linked list.

// Each node of the linked list is represented as a pair of [val, random_index] where:
// 1. val represents node.data.
// 2. random_index (1-based index) represents the index of the node that the random pointer of the current node points to, or NULL if it does not point to any node.

//Examples:
// Input: head = [[1, 3], [3, 3], [5, NULL], [9, 3]] 
// Output: [[1, 3], [3, 3], [5, NULL], [9, 3]]
// Explanation: 
// Node 1 points to Node 3 as its NEXT and Node 5 as its RANDOM.
// Node 3 points to Node 5 as its NEXT and Node 5 as its RANDOM.
// Node 5 points to Node 9 as its NEXT and NULL as its RANDOM.
// Node 9 points to NULL as its NEXT and Node 5 as its RANDOM.

#include<bits/stdc++.h>
using namespace std;

// Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = random = nullptr;
    }
};

class Solution {
public:
    Node* cloneLinkedList(Node* head) {
        if (head == nullptr)
            return nullptr;

        // Step 1: Create copy nodes and insert them after original nodes

        Node* curr = head;
        while (curr != nullptr) {
            Node* copy = new Node(curr->data);

            copy->next = curr->next;
            curr->next = copy;

            curr = copy->next;
        }


        // Step 2: Set random pointers of copied nodes

        curr = head;
        while (curr != nullptr) {
            Node* copy = curr->next;

            if (curr->random != nullptr)
                copy->random = curr->random->next;
            else
                copy->random = nullptr;

            curr = copy->next;
        }


        // Step 3: Separate original and copied lists

        curr = head;
        Node* copyHead = head->next;

        while (curr != nullptr) {
            Node* copy = curr->next;
            curr->next = copy->next;

            if (copy->next != nullptr)
                copy->next = copy->next->next;

            curr = curr->next;
        }

        return copyHead;
    }
};