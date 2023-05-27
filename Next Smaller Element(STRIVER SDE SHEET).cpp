//same logic as next greater element done earlier

#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int>st;
    st.push(-1);
    vector<int>ans(n,-1);
    for(int i=n-1;i>=0;i--){
        if(st.top()<arr[i]){
            ans[i]=st.top();
            st.push(arr[i]);
        }
        else{
            while(st.top()>=arr[i]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(arr[i]);
        }
    }
    return ans;
}
