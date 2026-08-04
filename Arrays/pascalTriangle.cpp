//Given a positive integer n, return the nth row of pascal's triangle.
// Pascal's triangle is a triangular array of the binomial coefficients formed by summing up the elements of previous row.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        vector<int> row;
        
        row.push_back(1);
        
        for(int i=1;i<n;i++){
            vector<int> newrow;
            newrow.push_back(1);
            
            for(int j=1;j<i;j++){
                newrow.push_back(row[j-1] + row[j]);
            }
            
            newrow.push_back(1);
            
            row = newrow;
        }
        
        return row;
    }
};