//Given the head of two sorted linked lists consisting of nodes respectively. Merge both lists and return the head of the sorted merged list.

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

//Approach 1 :- Using array

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        vector<int> arr;
        
        while(head1 != nullptr){
            arr.push_back(head1->data);
            head1=head1->next;
        }
        
        while(head2 != nullptr){
            arr.push_back(head2->data);
            head2=head2->next;
        }
        
        sort(arr.begin(),arr.end());
        
        Node* curr = new Node(arr[0]);
        Node* newHead = curr;
        
        for(int i=1;i<arr.size();i++){
            curr->next = new Node(arr[i]);
            curr = curr->next;
        }
        
        return newHead;
    }
};

//Approach 2 :- Using recursion

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        if(head1 == nullptr){
            return head2;
        }
        
        if(head2 == nullptr){
            return head1;
        }
        
        if(head1->data <= head2->data){
            head1->next = sortedMerge(head1->next,head2);
            return head1;
        }else{
            head2->next = sortedMerge(head1,head2->next);
            return head2;
        }
    }
};

//Approach 3 :- Using iterative merge approach

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        Node* newHead = new Node(-1);
        Node* curr = newHead;
        
        while(head1 && head2){
            if(head1->data <= head2->data){
                curr->next = head1;
                head1 = head1->next;
            }else{
                curr->next = head2;
                head2 = head2->next;
            }
            curr = curr->next;
        }
        
        if(head1){
            curr->next = head1;
        }
        
        if(head2){
            curr->next = head2;
        }
        
        return newHead->next;
        
    }
};