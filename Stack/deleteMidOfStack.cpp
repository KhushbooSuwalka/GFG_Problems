//Given a stack s, delete the middle element of the stack without using any additional data structure. The middle element is defined as the floor(size of stack + 1) / 2)-th element from the bottom of the stack (using 1-based indexing).
// Note: The output shown by the compiler is the stack from top to bottom.

// Examples:
// Input: s = [10, 20, 30, 40, 50]
// Output: [50, 40, 20, 10]
// Explanation: The bottom-most element will be 10 and the top-most element will be 50. Middle element will be element at index 3 from bottom, which is 30. Deleting 30, stack will look like [10, 20, 40, 50].

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void solve(stack<int>& st,int count,int mid){
        if(count==mid){
            st.pop();
            return;
        }
        
        int x = st.top();
        st.pop();
        
        solve(st,count+1,mid);
        
        st.push(x);
    }
    
    void deleteMid(stack<int>& s) {
        int n = s.size();
        int mid = n/2;
        
        solve(s,0,mid);
    }
};

//Approach 2:- Using unordered_map

class Solution{
public:
    void deleteMid(stack<int>& st){

    }
};