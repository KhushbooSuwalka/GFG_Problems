//Kth from End of Linked List
// Given the head of a linked list and an integer k, return the kth node from the end of the linked list. If k is greater than the number of nodes in the list, return -1.

// Examples :
// Input: k = 2 , head--> 1-> 2-> 3-> 4-> 5-> 6-> 7-> 8-> 9-> NULL
// Output: 8 
// Explanation: The 2nd node from end is 8.

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
    int getKthFromLast(Node* head, int k) {
        //Count the total number of nodes
        int count = 0;
        Node* curr = head;
        
        while(curr != nullptr){
            count++;
            curr = curr->next;
        }
        
        //If k is greater than the list size
        if(k>count){
            return -1;
        }
        
        //Move to the (count-k)th node
        curr = head;
        for(int i=0;i<count-k;i++){
            curr = curr->next;
        }
        
        return curr->data;
    }
};

//Approach 2:- Using two pointer technique

class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        // Two-pointer approach to find the kth node from the end
        Node* slow =head;
        Node* fast =head;

        // Move the fast pointer k steps ahead
        while(k--){
            if(fast == nullptr){
                return -1;
            }
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while(fast!=nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        // slow now points to the kth node from the end
        return (slow != nullptr) ? slow->data : -1;
    }
};