//A deque is a double-ended queue that allows enqueue and dequeue operations from both the ends.

// Given a deque and q queries. The task is to perform some operation on dequeue according to the queries as given below:
// 1. pb: query to push back the element x.
// 2. pf: query to push element x(given with query) to the front of the deque.
// 3. pp_b(): query to delete element from the back of the deque.
// 4. f: query to return a front element from the deque. If the deque is empty return -1.

// Examples:
// Input: queries = [[ pf 5 ],[ pf 10 ],[ pb 6 ],[ f ],[ pp_b ]]
// Output: 10
// Explanation: 
// 1. After push front deque will be [5]
// 2. After push front deque will be [10, 5]
// 3. After push back deque will be [10, 5, 6]
// 4. Return front element which is 10
// 5. After pop back deque will be [10, 5]

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void pb(deque<int>& dq, int x) {
        dq.push_back(x);
        
    }

    void ppb(deque<int>& dq) {
        if(!dq.empty()){
            dq.pop_back();
        }
    }

        
    int front_dq(deque<int>& dq) {
        if(dq.empty()){
            return -1;
        }
        return dq.front();
    }
        

    void pf(deque<int>& dq, int x) {
         dq.push_front(x);
    }
};
