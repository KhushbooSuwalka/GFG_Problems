//You are given the head of a singly linked list. If a loop is present in the linked list then return the first node of the loop else return -1.
// Note: Internally, pos(1 based index) is used to denote the position of the node that tail's next pointer is connected to. If pos = 0, it means the last node points to null, indicating there is no loop. Note that pos is not passed as a parameter.

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
    int cycleStart(Node* head) {
        unordered_set<Node*> st;
        
        while(head!=nullptr){
            if(st.find(head) != st.end()){
                return head->data;
            }
            
            st.insert(head);
            head=head->next;
        }
        
        return -1;
    }
};

//Approach 2 :- Hare and Tortoise Algorithm OR Floyd's cycle finding algorithm

class Solution {
  public:
    int cycleStart(Node* head) {
        Node* slow=head;
        Node* fast=head;
        
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast){
                slow=head;
                
                while(slow!=fast){
                   slow=slow->next;
                   fast=fast->next;
                }
               
                return slow->data;
            }
        }
        
        return -1;
    }
};