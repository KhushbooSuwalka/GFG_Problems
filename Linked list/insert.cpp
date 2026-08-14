//Insert in a Singly Linked List
//Given the head of a Singly Linked List, a position pos and value val. Insert the val data at the given position (1-based index) of the Linked List and return the head of the modified Linked List.

//Examples:
// Input: pos = 3, val = 4
// 1->3->NULL
// Output: 1 -> 3 -> 4
// Explanation: After inserting 4 at position 3 we'll get our linked list as -
//1->3->4->NULL

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
    Node* insertPos(Node* head, int pos, int val) {
        Node *newNode = new Node(val);
        
        //if position is 1-insertion at beginning
        if(pos==1){
            newNode->next =head;
            head = newNode;
            return head;
        }
        
        Node*temp = head;
        for(int i=1;i<=pos-2;i++){
            temp = temp->next;
        }
        
        //if Position is invalid i.e. the pos is 2 times greater than the size of the Linked List
        if(temp == nullptr){
            delete newNode;
            return head;
        }
        
        newNode->next =temp->next;
        temp->next = newNode;
        return head;
        
    }
};
