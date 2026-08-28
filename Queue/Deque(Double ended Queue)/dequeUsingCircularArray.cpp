// Implement a Deque (Double Ended Queue) using a circular array, where the size of the array, n is given.
// The Deque must support the following operations:
// (i) insertFront(x): Adds an element x at the front of Deque.
// (ii) insertRear(x): Adds an element x at the rear of Deque.
// (iii) deleteFront(): Deletes an element from front of Deque. 
// (iv) deleteRear(): Deletes an element from rear of Deque.
// (v) frontEle(): Gets the front element from queue. Return -1 if it is empty.
// (vi) rearEle(): Gets the last element from queue. Return -1 if it is empty.

// There will be a sequence of queries queries[][]. The queries are represented in numeric form:
// 1 x : Call insertFront(x)
// 2 x : Call insertRear(x)
// 3 : Call deleteFront()
// 4 : Call deleteRear()
// 5 : Call frontEle()
// 6 : Call rearEle()
// You just have to implement the functions insertFront, insertRear, deleteFront, deleteRear, frontEle and rearEle and the driver code will handle the input & output.

// Note: It is guaranteed that all the queries are valid.

// Examples:
// Input: n = 3, q = 6, queries[][] = [[1, 3], [2, 5], [1, 6], [6], [3], [5]]
// Output: [5, 3]
// Explanation: Queries on Deque are as follows:
// insertFront(3): Insert 3 at the front of the Deque.
// insertRear(5): Insert 5 at the rear of the Deque.
// insertFront(6): Insert 6 at the front of the Deque.
// rearEle(): Return the rear element i.e 5.
// deleteFront(): Remove the front element 6 from the Deque.
// frontEle(): Return the front element i.e 3.

#include<stdio.h>
using namespace std;

class myDeque {

  public:
    int *arr;
    int front, size, capacity;
    
    myDeque(int n) {
        arr = new int[n];
        capacity = n;
        front = 0;
        size = 0;
    }

    void insertFront(int x) {
        if(size == capacity){
            return;
        }
        front = (front - 1 + capacity) % capacity;
        arr[front] = x;

        size++;
    }

    void insertRear(int x) {
        if(size == capacity){
            return;
        }
        int rear = (front + size) % capacity;
        arr[rear] = x;
        size++;
    }

    void deleteFront() {
        if(size == 0){
            return;
        }
        front = (front + 1)%capacity;
        size--;
    }

    void deleteRear() {
        if(size == 0){
            return;
        }
        size--;
        int rear = (front + size - 1)%capacity;
    }

    int frontEle() {
        if(size == 0){
            return -1;
        }
        return arr[front];
    }

    int rearEle() {
        if(size == 0){
            return -1;
        }
        int rear = (front + size -1)%capacity;
        return arr[rear];
    }
};