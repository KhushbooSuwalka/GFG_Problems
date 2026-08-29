// Implement a Deque (Double Ended Queue) using a doubly linked list.
// The Deque must support the following operations:
// (i) insertFront(x): Adds an element x at the front of Deque.
// (ii) insertRear(x): Adds an element x at the rear of Deque.
// (iii) deleteFront(): Deletes an element from front of Deque. 
// (iv) deleteRear(): Deletes an element from rear of Deque.
// (v) getFront(): Gets the front element from queue. Return -1 if it is empty.
// (vi) getRear(): Gets the last element from queue. Return -1 if it is empty.

// There will be a sequence of queries queries[][]. The queries are represented in numeric form:
// 1 x : Call insertFront(x)
// 2 x : Call insertRear(x)
// 3 : Call deleteFront()
// 4 : Call deleteRear()
// 5 : Call getFront()
// 6 : Call getRear()
// You just have to implement the functions insertFront, insertRear, deleteFront, deleteRear, getFront and getRear and the driver code will handle the input & output.

// Note: It is guaranteed that all the queries are valid.

// Examples:
// Input: q = 6, queries[][] = [[1, 3], [2, 5], [1, 6], [6], [3], [5]]
// Output: [5, 3]
// Explanation: Queries on Deque are as follows:
// insertFront(3): Insert 3 at the front of the Deque.
// insertRear(5): Insert 5 at the rear of the Deque.
// insertFront(6): Insert 6 at the front of the Deque.
// getRear(): Return the rear element i.e 5.
// deleteFront(): Remove the front element 6 from the Deque.
// getFront(): Return the front element i.e 3.

#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* prev;
    Node* next;

    Node(int x) {
        data = x;
        prev = next = nullptr;
    }
};

class myDeque {

  public:
    Node* front;
    Node* rear;
    
    myDeque() {
        front = rear = nullptr;
    }

    void insertFront(int x) {
        Node* newNode = new Node(x);
        
        if(front == nullptr){
            front = rear = newNode;
        }else{
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void insertRear(int x) {
        Node* newNode = new Node(x);
        
        if(rear == nullptr){
            front = rear = newNode;
        }else{
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
    }

    void deleteFront() {
        if(front == nullptr){
            return;
        }
        front = front->next;
        if(front){
            front->prev = nullptr;
        }else{
            rear = nullptr;
        }
    }

    void deleteRear() {
        if(rear == nullptr){
            return;
        }
        rear = rear->prev;
        if(rear){
            rear->next = nullptr;
        }else{
            front = nullptr;
        }
    }

    int getFront() {
        if(front==nullptr){
            return -1;
        }
        return front->data;
    }

    int getRear() {
        if(rear==nullptr){
            return -1;
        }
        return rear->data;
    }
};