//Given the head of a linked list. A linked list contains a cycle if its last node is connected to a previous node. If the given list contains a cycle, return the length of the cycle. Otherwise, return 0.
//Note: Internally, the driver code uses an integer x to represent the position (1-based indexing) of the node to which the last node is connected. If x = 0, it means last node points to null which indicating there is no loop.

// Example:
// Input: 1 -> 2 -> 3 -> 4 -> 5 -> 2 -> 3 .......
// Explanation: There exists a loop in the linked list 2 -> 3 -> 4 -> 5, the length of the loop is 4.

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

//Approach 1 :- Using hashing

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        unordered_set<Node*> st;
        Node* newNode = head;
        
        while(newNode!=nullptr){
            
            if(st.find(newNode) != st.end()){
                Node* current = newNode;
                int count =1;
                newNode = newNode->next; 
                
                while(current!=newNode){
                    count++;
                    newNode = newNode->next;
                }
                
                return count;
            }
            
            st.insert(newNode);
            newNode=newNode->next;
        }
        
        return 0;
    }
};

//Approach 2 :- Hare and Tortoise Algorithm OR Floyd's cycle finding algorithm

class Solution {
  public:
    int countNodes(Node* node){
        int count =1;
        Node* current = node;
        
        while(current->next != node){
            count++;
            current = current->next;
        }
        
        return count;
    }
    
    int lengthOfLoop(Node *head) {
        Node* slow=head;
        Node* fast=head;
        
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast){
                return countNodes(slow);
            }
        }
        
        return 0;
    }
};