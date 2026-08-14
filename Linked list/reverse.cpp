//Reverse a Linked List
// Given the head of a singly linked list. Reverse the linked list and return the head of the reversed list.

// Examples:
// Input: 1 -> 2 ->3 ->4->NULL
// Output: 4 -> 3 -> 2 -> 1

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
    Node* reverseList(Node* head) {
        Node* prev =nullptr;
        Node* curr =head;
    
        while(curr!=nullptr){
            Node* next = curr->next;
            curr->next =prev;
            
            prev=curr;
            curr=next;
        }
        
        return prev;  
    }
};

//Approach 2 :- Recursive approach

class Solution {
  public:
    Node* rec(Node* head){
        //base case
        if(!head->next){
            return head;
        }
        
        //recursive case
        Node* newHead = rec(head->next);
        
        //One step - single node ko reverse krna h
        Node* temp = head->next;
        temp->next =head;
        head->next = nullptr;
        return newHead;
        
    }
    
    Node* reverseList(Node* head) {
        if(!head) return nullptr;
        return rec(head);
    }
};