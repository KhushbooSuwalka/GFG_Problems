//Implement a Stack using an Array, where the size of the array, n is given.
// The Stack must support the following operations:
// (i) push(x): Insert an element x at the top of the stack.
// (ii) pop(): Remove the element from the top of the stack.
// (iii) peek(): Return the top element if not empty, else -1.
// (iv) isEmpty(): Return true if the stack is empty else return false.
// (v) isFull(): Return true if the stack is full else return false.
// There will be a sequence of queries queries[][]. The queries are represented in numeric form:
// 1 x : Call push(x)
// 2 : Call pop()
// 3 : Call peek()
// 4  : Call isEmpty()
// 5 : Call isFull()
// You just have to implement the functions push, pop, peek, isEmpty, and isFull. The driver code will handle the output.
// Note: All the queries are valid.

// Examples:
// Input: n = 3, q = 6, queries[][] = [[1, 5], [1, 3], [3], [2], [4], [5]]
// Output: [3, false, false]
// Explanation: Queries on stack are as follows:
// push(5) : Insert 5 at the top of the stack.
// push(3) : Insert 3 at the top of the stack.
// peek() : Return the top element i.e. 3.
// pop() : Remove the top element i.e. 3.
// isEmpty() : return false as the stack is not empty.
// isFull() : return false as the stack is not full. Capacity = 3.

#include<bits/stdc++.h>
using namespace std;

class myStack {
  public:
    int top;
    int capacity;
    int *arr;
    
    myStack(int n) {
        capacity = n;
        top = -1;
        arr = new int[n];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity-1;
    }

    void push(int x) {
        if (top==capacity-1){
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if(top == -1){
            return;
        }
        arr[top--];
    }

    int peek() {
        if(top == -1){
            return -1;
        }
        return arr[top];
    }
};