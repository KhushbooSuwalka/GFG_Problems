//Given the head of a doubly linked list, reverse the list and return the head of the reversed doubly linked list.
//Note: Driver code will print the returned list in both forward and backward directions.

// Examples:
// Input: 3 <-> 4 <-> 5
// Output: 5 <-> 4 <-> 3

#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class Solution {
  public:
    Node *reverse(Node *head) {
        if(!head && !head->next){
            return head;
        }
        
        Node* curr = head;
        Node* prevNode = NULL;
        
        while(curr){
            prevNode = curr->prev;
            curr->prev = curr->next;
            curr->next = prevNode;
            
            curr = curr->prev;
        }
        
        return prevNode->prev;
    }
};