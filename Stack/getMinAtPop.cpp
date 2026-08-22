//You are given an integer array arr[]. You need to first push the elements of the array into a stack and then print minimum in the stack at each pop until stack becomes empty.

// Examples:
// Input: arr[] = [1, 6, 43, 1, 2, 0, 5]
// Output: [0, 0, 1, 1, 1, 1, 1]
// Explanation: 
// After pushing the elements to the stack, 
// the stack will be 5->0->2->1->43->6->1. 
// Now, poping the elements from the stack:
// popping 5: min in the stack is 0. popped 5
// popping 0: min in the stack is 0. popped 0
// popping 2: min in the stack is 1. popped 2
// popping 1: min in the stack is 1. popped 1
// popping 43: min in the stack is 1. popped 43
// popping 6: min in the stack is 1. popped 6
// popping 1: min in the stack is 1. popped 1.

#include<bits/stdc++.h>
using namespace std;

stack<int> _push(int arr[], int n) {
    stack<int> st;
    
    for(int i=0;i<n;i++){
        st.push(arr[i]);
    }
    
    return st;
}

// Function to print minimum value in stack each time while popping.
void _getMinAtPop(stack<int> s) {
    vector<int> ans;

    // Stack ko reverse karenge
    stack<int> temp;

    while(!s.empty()) {
        temp.push(s.top());
        s.pop();
    }

    int mn = INT_MAX;

    // Bottom se elements process karo
    while(!temp.empty()) {
        mn = min(mn, temp.top());
        ans.push_back(mn);
        temp.pop();
    }
    
    // Actual popping top se hoti hai,isliye answer ko reverse karke print karo
    reverse(ans.begin(), ans.end());

    for(int x : ans) {
        cout << x << " ";
    }

}