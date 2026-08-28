//Given the head of a doubly linked list and an integer x, delete the node at the xth position (1-based indexing) and return the head of the modified list.

// Examples:
// Input: x = 3, 1 <-> 3 <-> 4 
// Output: 1 <-> 3

#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution {
  public:
    Node* delPos(Node* head, int x) {
        if(x==1){
            head = head->next;
            
            if (head != NULL) {
                head->prev = NULL;
            }
            
            return head;
        }
        
        Node* curr = head;
        Node* newHead = curr;
        
        for (int i=0;i<x-2;i++){
            curr = curr->next;
        }
        
        curr->next = curr->next->next;
        
        if (curr->next != NULL) {
            curr->next->prev = curr;
        }
        
        return newHead;
    }
};