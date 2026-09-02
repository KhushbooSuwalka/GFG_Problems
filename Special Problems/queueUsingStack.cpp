//Implement a Queue using stacks. You are allowed to use only stack data structures to implement the queue.
// The Queue must support the following operations:
// (i) enqueue(x): Insert an element x at the rear of the queue.
// (ii) dequeue(): Remove the element from the front of the queue.
// (iii) front(): Return the front element if the queue is not empty, else return -1.
// (iv) size(): Return the number of elements currently in the queue.

// There will be a sequence of queries queries[][]. The queries are represented in numeric form:
// 1 x : Call enqueue(x)
// 2: Call dequeue()
// 3: Call front()
// 4: Call size()
// You just have to implement the functions enqueue, dequeue, front and size. The driver code will handle the input and output.

// Examples:
// Input: q = 7, queries[][] = [[1, 5], [1, 3], [1, 4], [3], [2], [4], [3]]
// Output: [5, 2, 3]
// Explanation: Queries on queue are as follows:
// enqueue(5): Insert 5 at the rear of the queue.
// enqueue(3): Insert 3 at the rear of the queue.
// enqueue(4): Insert 4 at the rear of the queue.
// front(): Return the front element i.e 5.
// dequeue(): Remove the front element 5 from the queue.
// size(): Queue now has 2 elements.
// front(): Return the front element i.e 3.

#include<bits/stdc++.h>
using namespace std;

class myQueue {

  public:
    stack<int> s1,s2;
    
    myQueue() {
        // Initialize your data members
    }

    void enqueue(int x) {
        
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push the new item into s1
        s1.push(x);

        // Push everything back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void dequeue() {
        if(s1.empty()){
            return;
        }
        s1.pop();
    }

    int front() {
        if(s1.empty()){
            return -1;
        }
        return s1.top();
    }

    int size() {
        return s1.size();
    }
};
