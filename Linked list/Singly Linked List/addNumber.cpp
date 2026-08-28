//Add Number Linked Lists
//You are given the head of two singly linked lists head1 and head2 representing two non-negative integers. You need to return the head of the linked list representing the sum of these two numbers.
// Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

//Examples:
//Input: head1 -> 1 -> 2 -> 3 ->NULL , head2 -> 9 -> 9 -> 9 ->NULL  
//Output:  1 -> 1 -> 2 -> 2
// Explanation: Given numbers are 123 and 999. There sum is 1122.

#include<bits/stdc++.h>
using namespace std;

// Structure of Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:

    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;

        while (curr != NULL) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    Node* addTwoLists(Node* head1, Node* head2) {

        while (head1 != NULL && head1->data == 0)
            head1 = head1->next;

        while (head2 != NULL && head2->data == 0)
            head2 = head2->next;

        if (head1 == nullptr && head2 == nullptr)
            return new Node(0);
        
        // Reverse both linked lists Because normal addition starts from the last digit.
        head1 = reverse(head1);  
        head2 = reverse(head2);

        Node* p = head1;
        Node* q = head2;

        int carry = 0;  // Because before adding anything, there is no carry.

        Node* result = nullptr;
        Node* tail = nullptr;

        while (p != nullptr || q != nullptr || carry != 0) {

            int sum = carry;

            if (p != nullptr) {
                sum += p->data;
                p = p->next;
            }

            if (q != nullptr) {
                sum += q->data;
                q = q->next;
            }

            int digit = sum % 10;
            carry = sum / 10;

            Node* newNode = new Node(digit);

            if (result == nullptr) {
                result = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        result = reverse(result);

        return result;
    }
};