//Intersection of Two Linked Lists
//Given two linked lists head1 and head2, find the intersection of two linked lists. Each of the two linked lists contains distinct node values.
// Note: The order of nodes in this list should be the same as the order in which those particular nodes appear in input head1 and return null if no common element is present.

// Examples:
// Input: head1: 9->6->4->2->3->8 , head2: 1->2->8->6
// Output: 6->2->8
// Explanation: Nodes 6, 2 and 8 are common in both of the lists and the order will be according to LinkedList1. 

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
    Node* findIntersection(Node* head1, Node* head2) {
        unordered_set<int> st;
        
        Node* temp = head2;
        while(temp){
            st.insert(temp->data);
            temp = temp->next;
        }
        
        Node* result = NULL;
        Node* tail = NULL;
        
        while(head1){
            
            // If common element found
            if (st.find(head1->data) != st.end()){
                if (!result) {
                    result = tail = new Node(head1->data);
                } else {
                    tail->next = new Node(head1->data);
                    tail = tail->next;
                }
                
                // Remove to avoid duplicates
                st.erase(head1->data);
            }
            
            head1 = head1->next;
        }
        
        return result;
    }
};