//Array to Linked List 
//Creation of a Linked list
//You are given an array arr[] of integers. You have to construct a singly linked list from the elements of the arr[] and return the head of the linked list.

// Examples:
// Input: arr[] = [1, 2, 3, 4, 5]
// Output: 1 -> 2 -> 3 -> 4 -> 5 

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
    Node* insertNode(Node* root,int item){
        Node* temp = new Node(item);
        
        if(root == NULL){
            return temp;
        }
        
        Node* newNode = root;
        while(newNode->next != NULL){
            newNode = newNode->next;
        }
        
        newNode->next = temp;
        return root;
    }
    
    Node* arrayToList(vector<int>& arr) {
        int n = arr.size();
        Node* root = NULL;
        
        for(int i=0;i<n;i++){
            root = insertNode(root,arr[i]);
        }
        
        return root;
    }
};

//Approach 2:- Submitted

class Solution {
  public:
    Node* arrayToList(vector<int>& arr) {
        int n = arr.size();
        Node* head = new Node(arr[0]) ;
        Node* newNode = head;
        
        for(int i=1;i<n;i++){
            Node* temp = new Node(arr[i]);
            
            newNode->next = temp;
            newNode = temp;
        }
        
        return head;
    }
};