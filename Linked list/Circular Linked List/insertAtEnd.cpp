//Given the head of a circular linked list and an integer key, insert key at the end of the circular linked list and return the head of the updated list.

// Examples:
// Input: key = 5, 1 -> 7 -> 8 -> 10->1->7....
// Output: 1 -> 7 -> 8 -> 10 -> 5
// Explanation: After inserting 5 at the end of the given circular linked list, it has elements as 1, 7, 8, 10, 5.

#include<bits/stdc++.h>
using namespace std;

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
    Node* insertAtEnd(Node* head, int key) {
        Node* curr=head;
        Node* newHead = curr;
        Node* newNode = new Node(key);
        
        while(curr->next!=newHead){
            curr = curr->next;
        }
        
        curr->next = newNode;
        newNode->next = newHead;
        
        return newHead;
        
    }
};