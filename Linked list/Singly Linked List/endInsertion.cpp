//Linked List End Insertion
// You are given the head of a Singly Linked List and a value x, insert that value x at the end of the LinkedList and return the head of the modified Linked List.

// Examples :
// Input: x = 6, 1 -> 2 -> 3 -> 4 -> 5 ->NULL
// Output: 1 -> 2 -> 3 -> 4 -> 5 -> 6
// Explanation: We can see that 6 is inserted at the end of the linkedlist.

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
    Node *insertAtEnd(Node *head, int x) {
        Node* newNode = head;
        Node* temp =new Node(x);
        
        if (head == nullptr) {
            return temp;
        }
        
        while(newNode->next != nullptr){
            newNode = newNode->next;
        }
        
        newNode->next = temp;
        return head;
    }
};