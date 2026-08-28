// Given the head of a doubly-linked list, a position p, and an integer x. Insert a new node with value x at the position just after pth node (0-based indexing) in the doubly linked list and return the head of the modified list.

// Examples:
// Input: p = 2, x = 6 , head -> 2 <-> 4 <-> 5->NULL
// Output: 2 <-> 4 <-> 5 <-> 6
// Explanation: Insert a node of value 6 after the 2nd node.

#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};

class Solution {
  public:
    Node* insertAtPos(Node* head, int p, int x) {
        Node* newNode = new Node(x);
        Node* curr = head;
        Node* newHead=curr;
        
        for(int i=0;i<p;i++){
            curr = curr->next;
        }
        
        newNode->prev = curr;
        newNode->next = curr->next;
        
        if(curr->next){
            curr->next->prev = newNode;
        }
        
        curr->next = newNode;
        
        return newHead;
    }
};