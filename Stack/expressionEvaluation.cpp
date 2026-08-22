//Infix Evaluation
// You are given an array of strings arr[], that represents a valid infix expression. The task is to evaluate this expression.
// An infix expression is of the form "operand1 operator operand2" (e.g., "a + b"), where the operator is written between the two operands.
// Note: Infix expressions follow precedence: ^ (highest, right-to-left), then * and /, and finally + and - (left-to-right).
// The division operation between two integers always computes the floor value, i.e floor(5 / 3) = 1 and floor(-5 / 3) = -2.
// It is guaranteed that the result of the expression and all intermediate calculations will fit in a 32-bit signed integer.

//Example:
//Input: arr[] = ["100", "+", "200", "/", "2", "*", "5", "+", "7"]
// Output: 607

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int priority(string op) {
        if (op == "^")
            return 3;
        if (op == "*" || op == "/")
            return 2;
        return 1;   // + or -
    }
    
    int calculate(int a, int b, string op) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        if (op == "/") return a / b;

        return pow(a, b);
    }
    
    int evaluateInfix(vector<string>& arr) {
        stack<int> nums;
        stack<string> ops;
        
        for (string x : arr) {

            // If x is a number
            if (x != "+" && x != "-" && x != "*" && x != "/" && x != "^") {
                nums.push(stoi(x));
            }

            // If x is an operator
            else {

                while (!ops.empty() && priority(ops.top()) >= priority(x) && x != "^") {
                    int b = nums.top();
                    nums.pop();

                    int a = nums.top();
                    nums.pop();

                    string op = ops.top();
                    ops.pop();

                    nums.push(calculate(a, b, op));
                }

                ops.push(x);
            }
        }

        // Calculate remaining operators
        while (!ops.empty()) {
            int b = nums.top();
            nums.pop();

            int a = nums.top();
            nums.pop();

            string op = ops.top();
            ops.pop();

            nums.push(calculate(a, b, op));
        }

        return nums.top();
    }
};