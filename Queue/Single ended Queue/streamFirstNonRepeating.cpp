//Given a string s consisting of only lowercase alphabets, for each index i in the string (0 ≤ i < n), find the first non-repeating character in the prefix s[0..i]. If no such character exists, use '#'.

// Examples:
// Input: s = "aabc"
// Output: a#bb
// Explanation: 
// At i=0 ("a"): First non-repeating character is 'a'.
// At i=1 ("aa"): No non-repeating character, so '#'.
// At i=2 ("aab"): First non-repeating character is 'b'.
// At i=3 ("aabc"): Non-repeating characters are 'b' and 'c'; 'b' appeared first, so 'b'.

#include<bits/stdc++.h>
using namespace std;

string firstNonRepeating(string& s){
    string ans = "";
    vector<int> count(26, 0);  
    queue<char> q;

    for(char ch : s) {
        
        // if non-repeating element found push it in queue
        if (count[ch - 'a'] == 0) {
            q.push(ch);
        }

        // Update frequency
        count[ch - 'a']++;

        // If front element is repeating pop it from the queue
        while (!q.empty() && count[q.front() - 'a'] > 1) {
            q.pop();
        }

        // if queue is not empty append front element, else append "#" in ans string.
        if (!q.empty()) {
            ans += q.front();
        }
        else {
            ans += '#';
        }
    }

    return ans;
}

int main()
{
    string s = "aabc";
    string ans = firstNonRepeating(s);
    cout << ans << "\n";  
    return 0;
}