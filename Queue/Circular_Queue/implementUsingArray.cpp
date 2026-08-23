//Implementation of Circular Queue Using Array
//A circular queue is a linear data structure that overcomes the limitations of a simple queue. In a normal array implementation, dequeue() can be O(n) or we may waste space. Using a circular array, both enqueue() and dequeue() can be done in O(1).
//Operations :- 
//Enqueue(x) :- Insert an element x at the rear of the circular queue.
//Dequeue() :- Remove and return the front element from the circular queue.

#include<bits/stdc++.h>
using namespace std;

class myQueue {
private:
     // fixed-size array
    int* arr;  
     // index of front element
    int front; 
     // current number of elements
    int size;   
    // maximum capacity
    int capacity;

public:
    myQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        size = 0;
    }

    // Insert an element at the rear
    void enqueue(int x) {
        if (size == capacity) {
            cout << "Queue is full!" << endl;
            return;
        }
        int rear = (front + size) % capacity;
        arr[rear] = x;
        size++;
    }

    // Remove an element from the front
    int dequeue() {
        if (size == 0) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int res = arr[front];
        front = (front + 1) % capacity;
        size--;
        return res;
    }

    // Get the front element
    int getFront() {
        if (size == 0) return -1;
        return arr[front];
    }

    // Get the rear element
    int getRear() {
        if (size == 0) return -1;
        int rear = (front + size - 1) % capacity;
        return arr[rear];
    }
};

int main() {
    myQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.getFront() << " " << q.getRear() << endl;
    q.dequeue();
    cout << q.getFront() << " " << q.getRear() << endl;
    q.enqueue(40);
    cout << q.getFront() << " " << q.getRear() << endl;
    return 0;
}