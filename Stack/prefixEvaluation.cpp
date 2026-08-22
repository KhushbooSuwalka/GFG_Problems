//You are given an array of strings arr[] representing a prefix expression. Your task is to evaluate the expression and return an integer representing its value.
// Note: A prefix expression is of the form "operator operand1 operand2" (e.g., + a b).
// And the division operation between two integers always computes the floor value, i.e floor(5 / 3) = 1 and floor(-5 / 3) = -2.
// It is guaranteed that the result of the expression and all intermediate calculations will fit in a 32-bit signed integer.

// Examples:
// Input: arr[] = ["+", "*", "/", "+", "100", "200", "2", "5", "7"]
// Output: 757
// Explanation: If the expression is converted into an infix expression, it will be ((100 + 200) / 2) * 5 + 7  = 150 * 5 + 7 = 757.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int evaluatePrefix(vector<string>& arr) {
        stack<int> num;
        int n=arr.size();
        
        for(int i=n-1;i>=0;i--){
            if(arr[i]!="+" && arr[i]!="-" && arr[i]!="*" && arr[i]!="/" && arr[i]!="^"){
                num.push(stoi(arr[i]));
            }
            else{
                int a = num.top();
                num.pop();
                
                int b = num.top();
                num.pop();

                if(arr[i] == "+") {
                    num.push(a + b);
                }
                else if(arr[i] == "-") {
                    num.push(a - b);
                }
                else if(arr[i] == "*") {
                    num.push(a * b);
                }
                else if(arr[i] == "/") {
                    num.push(floor((double)a / b));
                }
                else if(arr[i] == "^") {
                    num.push((int)pow(a, b));
                }
            }
        }
        
        return num.top();
    }
};