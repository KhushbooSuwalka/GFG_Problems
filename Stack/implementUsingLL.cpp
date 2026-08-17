//Implement a Stack using a Linked List. The stack has dynamic size and can grow until memory is available.

//Examples:
// Input: q = 7, queries[][] = [[1, 5], [1, 3], [1, 4], [3], [2], [5], [4]]
// Output: [4, 2, false]
// Explanation: Queries on queue are as follows:
// push(5): Insert 5 at the top of the stack.
// push(3): Insert 3 at the top of the stack.
// push(4): Insert 4 at the top of the stack.
// peek(): Return the top element i.e 4.
// pop(): Remove the top element 4 from the stack.
// size(): Stack contains 2 elements return 2.
// isEmpty(): Stack is not empty return false.

#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class myStack {

  public:
    Node* head;
    int count;
    
    myStack() {
       head = nullptr;
       count = 0;
    }

    bool isEmpty() {
        if(head==nullptr){
            return true;
        }
        return false;
    }

    void push(int x) {
        Node* temp = new Node(x);
        temp->next = head;
        head = temp;
        
        count++;
    }

    void pop() {
        if(head == nullptr){
            return;
        }
        Node* temp = head;
        head = head->next;
        count--;

        delete temp;
    }

    int peek() {
        if(head == nullptr){
            return -1;
        }
        return head->data;
    }

    int size() {
        return count;
    }
};