//Merge K sorted linked lists
//Given an array arr[] of n sorted linked lists of different sizes. Your task is to merge all these lists into a single sorted linked list and return the head of the merged list.

//Examples:-
//Output: 1 -> 2 -> 3 -> 4 -> 7 -> 8 -> 9
// Explanation: The arr[] has 3 sorted linked list of size 3, 3, 1.
// 1st list: 1 -> 3 -> 7
// 2nd list: 2 -> 4 -> 8
// 3rd list: 9

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
    Node* merge(Node* head1,Node* head2){
        Node* dummy = new Node(-1);
        Node* curr = dummy;
        
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
        
        return dummy->next;
    }
    
    Node* mergeRecursion(vector<Node*>& arr, int low, int high){
        if(low==high){
            return arr[low];
        }
        
        int mid = (low + high)/2;
        Node* head1 = mergeRecursion(arr,low,mid);
        Node* head2 = mergeRecursion(arr,mid+1,high);
        Node* head = merge(head1,head2);
        
        return head;
    }
    
    Node* mergeKLists(vector<Node*>& arr) {
        int n = arr.size();
        if(n == 0){
            return nullptr;
        }
        
        return mergeRecursion(arr,0,n-1);
    }
};