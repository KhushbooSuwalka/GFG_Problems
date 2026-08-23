#include <iostream>
using namespace std;

class MyDeque {
    int arr[1000];
    int front;
    int rear;
    int size;

public:
    MyDeque() {
        front = -1;
        rear = -1;
        size = 1000;
    }

    // Push at front
    void pf(int x) {
        if ((front == 0 && rear == size - 1) ||
            (front == rear + 1)) {
            return; // deque full
        }

        // Empty deque
        if (front == -1) {
            front = rear = 0;
        }

        // Front is at 0, move it circularly
        else if (front == 0) {
            front = size - 1;
        }

        // Normal case
        else {
            front--;
        }

        arr[front] = x;
    }

    // Push at back
    void pb(int x) {
        if ((front == 0 && rear == size - 1) ||
            (front == rear + 1)) {
            return; // deque full
        }

        // Empty deque
        if (front == -1) {
            front = rear = 0;
        }

        // Rear is at last position
        else if (rear == size - 1) {
            rear = 0;
        }

        // Normal case
        else {
            rear++;
        }

        arr[rear] = x;
    }

    // Pop from back
    void ppb() {
        if (front == -1) {
            return; // empty
        }

        // Only one element
        if (front == rear) {
            front = rear = -1;
        }

        // Rear is at first position
        else if (rear == 0) {
            rear = size - 1;
        }

        // Normal case
        else {
            rear--;
        }
    }

    // Return front
    int front_dq() {
        if (front == -1) {
            return -1;
        }

        return arr[front];
    }
};