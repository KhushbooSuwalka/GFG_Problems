//Given an array arr[] of n sorted linked lists of different sizes. Your task is to merge all these lists into a single sorted linked list and return the head of the merged list.

// Examples:
// Output: 1 -> 2 -> 3 -> 4 -> 7 -> 8 -> 9
// Explanation: The arr[] has 3 sorted linked list of size 3, 3, 1.
// 1st list: 1 -> 3 -> 7
// 2nd list: 2 -> 4 -> 8
// 3rd list: 9

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
public:
    Node* mergeTwoLists(Node* head1, Node* head2) {
        Node* dummy = new Node(-1);
        Node* temp = dummy;

        while(head1 != NULL && head2 != NULL) {

            if(head1->data <= head2->data) {
                temp->next = head1;
                head1 = head1->next;
            }
            else {
                temp->next = head2;
                head2 = head2->next;
            }

            temp = temp->next;
        }

        // Jo list bach gayi
        if(head1 != NULL)
            temp->next = head1;
        else
            temp->next = head2;

        return dummy->next;
    }

    Node* mergeKLists(vector<Node*>& arr) {
        Node* ans = NULL;

        for(int i = 0; i < arr.size(); i++) {
            ans = mergeTwoLists(ans, arr[i]);
        }

        return ans;
    }
};