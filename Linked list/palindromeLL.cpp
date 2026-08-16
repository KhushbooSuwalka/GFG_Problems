//You are given the head of a singly linked list of positive integers. You have to check if the given linked list is palindrome or not.

// Example:
// Output: true
// Explanation: The given linked list is 1 -> 2 -> 1 -> 1 -> 2 -> 1, which is a palindrome.

//Approach:- Find the middle of the linked list. Reverse only the second half. Compare the first half with the reversed second half.

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

    Node* reverseNode(Node* head) {
        Node* curr = head;
        Node* prev = nullptr;

        while(curr != nullptr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    bool isPalindrome(Node* head) {
        if(head == nullptr || head->next == nullptr) {
            return true;
        }

        Node* slow = head;
        Node* fast = head;

        // Find middle
        while(fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        Node* firstHalf = head;
        Node* secondHalf = reverseNode(slow->next);
        Node* curr = secondHalf;

        // Compare both halves
        while(curr != nullptr) {
            if(firstHalf->data != curr->data) {
                return false;
            }

            firstHalf = firstHalf->next;
            curr = curr->next;
        }

        return true;
    }
};