//Given a queue q containing integer elements, your task is to reverse the queue.

// Examples:
// Input: q[] = [5, 10, 15, 20, 25]
// Output: [25, 20, 15, 10, 5]
// Explanation: After reversing the given elements of the queue, the resultant queue will be 25 20 15 10 5.

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    void reverseQueue(queue<int>& q) {
        stack<int> st;
    
        // Transfer all elements from queue to stack
        while (!q.empty()) {
            st.push(q.front());
            q.pop();
        }
    
        // Transfer all elements back from stack to queue. This reverses the order
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }
    }
};