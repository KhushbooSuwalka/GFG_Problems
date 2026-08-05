//Given an unsorted array arr[] of size n, containing elements from the range 1 to n, it is known that one number in this range is missing, and another number occurs twice in the array, find both the duplicate number and the missing number.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int> res(2);
        int n=arr.size();
        
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                res[0] = arr[i];
                break;
            }
        }
        
        int expected = 1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == expected) {
                expected++;
            } else if (arr[i] > expected) {
                res[1] = expected;
                return res;
            }
        }
        res[1] = expected;
        
        return res;
        
    }
};