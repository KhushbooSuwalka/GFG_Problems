//Given a positive integer n, find the square root of n. If n is not a perfect square, then return the floor value.
//Floor value of any number is the greatest Integer which is less than or equal to that number.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int floorSqrt(int n){  
        int l=0,r=n;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            long long sq=1LL*mid*mid;
            if(sq==n){
                return mid;
            }else if(sq<n){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};

//Approach 2 :- Using nested loops

class Solution {
  public:
    int floorSqrt(int n) {
        int ans = 0;

        for(int i = 1; i <= n; i++)
        {
            if(i * i <= n)
                ans = i;
            else
                break;
        }

        return ans;
        
    }
};

