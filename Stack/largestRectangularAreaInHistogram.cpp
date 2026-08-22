//Histogram Max Rectangular Area
//Given a histogram represented by an array arr[], where each element of the array denotes the height of the bars in the histogram. All bars have the same width of 1 unit.
// Find the largest rectangular area possible in the given histogram, where the rectangle can be formed using a number of contiguous bars.

// Examples:
// Input: arr[] = [60, 20, 50, 40, 10, 50, 60]
// Largest-Rectangular-Area-in-a-Histogram
// Output: 100
// Explanation: We get the maximum by picking bars highlighted above in green (50, and 60). The area is computed = 50 * 2 = 100.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMaxArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;   // Monotonic Increasing Stack :- When a smaller value comes, we pop until the increasing order is restored.
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {

            int currHeight;
            if(i == n){
                currHeight=0;
            }else{
                currHeight=arr[i];
            }

            while (!st.empty() && arr[st.top()] > currHeight) {

                int height = arr[st.top()];
                st.pop();

                int width;

                if (st.empty()) {
                    width = i;
                } else {
                    width = i - st.top() - 1;
                    // width = right - left - 1 , i.e. width = NSE - PSE - 1 , where NSE is the next smaller element index and PSE is the previous smaller element index 
                }

                maxArea = max(maxArea, height * width);
            }

            if (i < n)
                st.push(i);   
                // Stack contains the indices of array of heights of bars of histogram.
        }

        return maxArea;
    }
};

// Approach 2 :- Using two stacks 

class Solution {
public:
    int getMaxArea(vector<int>& arr) {
        int n = arr.size();

        vector<int> pse(n);
        vector<int> nse(n);

        stack<int> left;
        stack<int> right;

        // Find Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!left.empty() && arr[left.top()] >= arr[i]) {
                left.pop();
            }

            if (left.empty())
                pse[i] = -1;
            else
                pse[i] = left.top();

            left.push(i);
        }

        // Find Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!right.empty() && arr[right.top()] >= arr[i]) {
                right.pop();
            }

            if (right.empty())
                nse[i] = n;
            else
                nse[i] = right.top();

            right.push(i);
        }

        // Calculate maximum area
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            int area = arr[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};