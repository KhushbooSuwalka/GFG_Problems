//Intersection in Y Shaped Lists
//Given the heads of two non-empty singly linked lists, head1 and head2, return the node where the two linked lists intersect. It is guaranteed that an intersection always exists.
// Note: The custom input contains a non-empty list common. Initially, head1 and head2 do not share any node. The last node of each list is then connected to the head of common, creating an intersection at the first node of common.

//Examples:
// Input: head1: 10 -> 15 -> 30, head2: 3 -> 6 -> 9 -> 15 -> 30
// Output: 15
// Explanation: From the image, it is clear that the common part is 15 -> 30, and its starting node is 15.

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
    Node* intersectPoint(Node* head1, Node* head2) {
        unordered_set<Node*> st;
        
        Node* curr1= head1;
        while(curr1 != nullptr){
            st.insert(curr1);
            curr1 = curr1->next;
        }
        
        Node* curr2 = head2;
		while (curr2 != nullptr) {
		    if (st.find(curr2) != st.end()) {
		        
		        //Intersection point found
		        return curr2;
		    }
		    curr2 = curr2->next;
		}

		return nullptr;
    }
};