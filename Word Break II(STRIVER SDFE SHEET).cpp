#include <bits/stdc++.h> 

void solve(int indx, string s, unordered_map<string, int> &mpp, string ds, vector<string> &ans) {
    // base case: if you reach end of string s, then you have the answer stored in ds, push it in ans & return
    if(indx == s.size()) {
        ans.push_back(ds);
        return;
    }
    
    string tmp = "";
    for(int i = indx; i < s.length(); ++i) {
        // keep on adding current char in tmp, until you find the word in mpp
        tmp = tmp + s[i];
        if(mpp[tmp]) {
            // if current word exists in map then recursively call to complete the sentence breaking s from here
            string next = ds + tmp + " ";
            solve(i + 1, s, mpp, next, ans);
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // make a map of dictionary words
    unordered_map<string, int> mpp;
    for(int i = 0; i < dictionary.size(); ++i) {
        mpp[dictionary[i]]++;
    }
    
    vector<string> ans;
    string ds;        // temporary for holding the sentence being formed in each recursive call
    solve(0, s, mpp, ds, ans);    
    return ans;
}
