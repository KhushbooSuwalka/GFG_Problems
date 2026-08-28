// You are given the head of a linked list, You have to return the value of the middle node of the linked list.
// If the number of nodes is odd, return the middle node value.
// If the number of nodes is even, there are two middle nodes, so return the second middle node value.

// Examples:
// Input: 1->2->3->4->5->NULL
// Output: 3
// Explanation: The given linked list is 1->2->3->4->5 and its middle is 3.

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

//Approach 1 :- Two passes

class Solution{
public:
  int getLength(Node* head){
    int count =0;

    while(head){
      count++;
      head = head->next;
    }

    return count;
  }

  int getMiddle(Node* head){
    int length = getLength(head);

    // traverse till we reached half of length
    int midIndex = length / 2;
    while (midIndex--) {
      head = head->next;
    }

    return head->data;
  }

};

//Approach 2 :- Hare and Tortoise Algorithm OR Floyd's cycle finding algorithm

class Solution {
  public:
    int getMiddle(Node* head) {
        Node* slowptr = head;
        Node* fastptr = head;
        
        while (fastptr != NULL && fastptr->next != NULL) {
            // move the fast pointer by two nodes
            fastptr = fastptr->next->next;

            // move the slow pointer by one node
            slowptr = slowptr->next;
        }

        return slowptr->data;
    }
};