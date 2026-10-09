//There are n rooms in a straight line in Geekland State University's hostel. You are given a binary string s of length n, where s[i] = '1' means there is a WiFi router in the i-th room, and s[i] = '0' means there is no WiFi in that room.
// Each WiFi router has a range of x, meaning it can cover up to x rooms to its left and x rooms to its right.
// Given x and s, find if all rooms are covered by at least one WiFi router.

// Examples: 
// Input: x = 0, s = "010"
// Output: false
// Explanation: Since the range is 0, so Wifi is only accessible in second room while 1st & 3rd room have no wifi. Therefore answer is false for this test case.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool wifiRange(string &s, int x) {
        int n=s.size();
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                continue;
            } else {
                bool covered = false;

                //Left side check
                for(int j=max(0,i-x);j<i;j++){
                    if(s[j]=='1'){
                        covered=true;
                        break;
                    }
                }
                
                if(!covered){
                    //Right side check
                    for(int j=i+1;j<=min(n-1,i+x);j++){
                        if(s[j]=='1'){
                            covered=true;
                            break;
                        }
                    }
                }
                
                //If the room is not covered by any WiFi router, return false
                if(!covered)  return false;
            }
        }
        
        return true;
    }
};