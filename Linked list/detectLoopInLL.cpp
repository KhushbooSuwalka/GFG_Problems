// You are given the head of a singly linked list. You have to determine whether the given linked list contains a loop or not. A loop exists in a linked list if the next pointer of the last node points to any other node in the list (including itself), rather than being null.
// Note: Internally, pos(1 based index) is used to denote the position of the node that tail's next pointer is connected to. If pos = 0, it means the last node points to null. Note that pos is not passed as a parameter

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

//Approach 1 :- Using Hashing

class Solution {
  public:
    bool detectLoop(Node* head) {
        unordered_set<Node*> st;
        
        while(head!=nullptr){
            if(st.find(head) != st.end()){
                return true;
            }
            
            st.insert(head);
            head = head->next;
        }
        
        return false;
    }
};

//Approach 2 :- Hare and Tortoise Algorithm OR Floyd's cycle finding algorithm

class Solution {
  public:
    bool detectLoop(Node* head) {
        Node* slow=head;
        Node* fast=head;
        
        while(slow!= nullptr && fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast){
                return true;
            }
        }
        
        return false;
    }
};