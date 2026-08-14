//Linked List Delete at Position
// Given the head of a linked list and an integer x, delete the node at position x and return the updated head of the linked list.
// Note: Positions use 1-based indexing.

// Examples:
// Input: x = 4, 1 -> 2-> 3->4 -> 5 ->NULL
// Output: 1 -> 2 -> 3 -> 5

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
    Node* deleteNode(Node* head, int x) {
        Node* temp =head;
        
        if(x==1){
            head=head->next;
            return head;
        }
        
        for(int i=1;i<=x-2;i++){
            temp=temp->next;
        }
        
        if(temp ==nullptr){
            delete temp;
            return head;
        }
        
        temp->next =temp->next->next;
        return head;
    }
};