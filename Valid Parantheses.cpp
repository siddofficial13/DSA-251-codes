#include<bits/stdc++.h>
bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<char>st;
    for(auto it:s){
        if(it=='(' || it=='{' || it=='['){
            st.push(it);
        }
        else{
            if(st.size()==0){
                return false;
            }
            char ch=st.top();
            st.pop();
            if((it == ')' and ch == '(') or  (it == ']' and ch == '[') or (it == '}' and ch == '{')) continue;
                else return false;
        }
    }
    return st.empty();
}
