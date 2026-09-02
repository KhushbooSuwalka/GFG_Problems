//Implement a Stack using Queue data structure, this stack has no fixed capacity and can grow dynamically until memory is available.
// The Stack must support the following operations:
// (i) push(x): Insert an element x at the top of the stack.
// (ii) pop(): Remove the element from the top of the stack, if stack is empty do nothing.
// (iii) top(): Return top element if not empty, else -1.
// (iv) size(): Return the number of elements currently in the stack.

// There will be a sequence of queries queries[][]. The queries are represented in numeric form:
// 1 x: Call push(x)
// 2: Call pop()
// 3: Call top()
// 4: Call size()
// You just have to implement the functions push, pop, top and size. The driver code will handle the input and output.

// Examples:
// Input: q = 6, queries[][] = [[1, 5], [1, 3], [1, 4], [3], [2], [4]]
// Output: [4, 2]
// Explanation: Queries on queue are as follows:
// push(5): Insert 5 at the top of the stack.
// push(3): Insert 3 at the top of the stack.
// push(4): Insert 4 at the top of the stack.
// top(): Return the top element i.e 4.
// pop(): Remove the top element 4 from the stack.
// size(): Stack contains 2 elements return 2.

#include<bits/stdc++.h>
using namespace std;

class myStack {
    queue<int> q;

  public:

    void push(int x) {
        q.push(x);

        int sz = q.size();
        for (int i = 0; i < sz - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if(!q.empty()){
            q.pop();
        }
    }

    int top() {
        if(q.size()==0){
            return -1;
        }
        return q.front();
    }

    int size() {
        return q.size();
    }
};

//Approach 2:-Using two queues

#include <iostream>
#include <queue>
using namespace std;

class myStack {
    
    queue<int> q1, q2;

public:
    void push(int x) {
        
        // Push x first in empty q2
        q2.push(x);

        // Push all the remaining
        // elements in q1 to q2.
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // swap the names of two queues
        swap(q1, q2);
    }

    void pop()
    {
        // if no elements are there in q1
        if (q1.empty())
            return;
        q1.pop();
    }

    int top()
    {
        if (q1.empty())
            return -1;
        return q1.front();
    }

    int size() { return q1.size(); }
};

int main() {
    myStack st;
    st.push(1);
    st.push(2);
    st.push(3);

    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;

    cout << st.size() << endl;
    return 0;
}