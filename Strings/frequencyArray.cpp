#include<bits/stdc++.h>
using namespace std;

int main(){
    string s="geeksforgeeks";
    vector<int> freq(26,0);

    for(char ch : s){
        int idx = ch-'a';
        freq[idx]++;
    }

    for(int i = 0; i < 26; i++){
        // if(freq[i] > 0){
            char ch = i + 'a';
            cout << ch << " " << freq[i] << endl;
        // }
    }

    return 0;
}