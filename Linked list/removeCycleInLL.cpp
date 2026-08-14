//Given the head of a singly linked list. A cycle exists if the last node points back to a previous node, forming a loop. Remove the loop from the linked list if it exists.
// Internally, the driver code uses a variable x (1-based indexing) to represent the position of the node to which the last node is connected.
// The driver code will print "true" if the linked list is correctly modified, otherwise it will print "false".

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
    void removeLoop(Node* head) {
        unordered_set<Node*> st;
        Node* prev = nullptr;
        
        while(head != nullptr){
            if(st.find(head) == st.end()){
                st.insert(head);
                prev = head;
                head = head->next;
            }else{
                prev->next = nullptr;
                break;
            }
        }
    }
};

//Approach 2 :- Hare and Tortoise Algorithm OR Floyd's cycle finding algorithm

class Solution {
  public:
    void removeLoop(Node* head) {
        if(head==nullptr || head->next ==nullptr){
            return;
        }
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow==fast){
                slow = head;
                
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                
                Node* temp = fast;
                while(temp->next != fast){
                    temp = temp->next;
                }
                
                temp->next = nullptr;
                return;
            }
            
        }
    }
};