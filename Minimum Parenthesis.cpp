#include <bits/stdc++.h> 
int minimumParentheses(string pattern) {
    // Write your code here.
    // pattern is the given string.
    int n = pattern.size();
    vector<char>v;
    int count=0;
    for(int i =0;i<n;i++){
        if(pattern[i]=='('){
            v.push_back(pattern[i]);
        }
        if(pattern[i]==')'){
            if(v.size()==0){
                count++;
            }
            else{
                v.pop_back();
            }
        }
    }
    return count+v.size();
}
