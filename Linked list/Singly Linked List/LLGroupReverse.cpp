//Given the head of a Singly linked list. Reverse every k node in the linked list and return the head of the modified list.
// Note: If the number of nodes is not a multiple of k then the left-out nodes at the end, should be considered as a group and must be reversed.

//Examples:
// Input: head: 1 -> 2 -> 3 -> 4 -> 5 -> 6, k = 2
// Output: 2 -> 1 -> 4 -> 3 -> 6 -> 5
// Explanation: Linked List is reversed in a group of size k = 2.

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

//Approach 1 :- Iterative k-Group Reversal

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        if(head == nullptr){
            return head;
        }   
        
        Node* curr = head;
        Node* newHead = nullptr;
        Node* tail = nullptr;
        
        while (curr != nullptr){
            Node* groupHead = curr;
            Node* prev = nullptr;
            Node* nextNode = nullptr;
            int count = 0 ;
            
            while(curr != nullptr && count < k){
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
                count++;
            }
            
            if(newHead == nullptr){
                newHead = prev;
            }
            
            if(tail != nullptr){
                tail->next = prev;
            }
            
            tail = groupHead;
        }
        
        return newHead;
    }
};

//Approach 2 :- Recursive k-Group Reversal

class Solution {
  public:
    Node *reverseNodes(Node *head,int k){
        Node* curr = head;
        Node* prev = nullptr;
        Node* nextNode = nullptr;
        int count = 0 ;
        
         while(curr != nullptr && count < k){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count++;
        }
        
        return prev;
    }
    
    Node *reverseKGroup(Node *head, int k) {
        if(head == nullptr){
            return head;
        }   
        
        Node* groupHead = nullptr;
        Node* newHead = nullptr;
        
        Node *temp = head;
        int count = 0;
        
        while (temp && count < k){
            temp = temp->next;
            count++;
        }
        
        groupHead = reverseNodes(head,k);
            
        if(newHead == nullptr){
            newHead = groupHead;
        }
        
        head->next = reverseKGroup(temp,k);
        
        return newHead;
    }
};

//OR

class Solution {
  public:
    Node *reverseNodes(Node *head,int k){
        Node* curr = head;
        Node* prev = nullptr;
        Node* nextNode = nullptr;
        int count = 0 ;
        
         while(curr != nullptr && count < k){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count++;
        }
        
        return prev;
    }
    
    Node *reverseKGroup(Node *head, int k) {
        if(head == nullptr || k<=1){
            return head;
        }   
        
        //Move temp to next group 
        Node *temp = head;
        int count = 0;
        
        while (temp && count < k){
            temp = temp->next;
            count++;
        }
        
        if (count < k) {
            return head;
        }
        
        Node* newHead = reverseNodes(head,k);
        
        head->next = reverseKGroup(temp,k);
        
        return newHead;
    }
};