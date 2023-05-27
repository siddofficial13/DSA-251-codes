#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
   
    int n =price.size();
     vector<int>ans(n,1);
    // ans.push_back(1);
    // for(int i=1;i<n;i++){
    //     int count=1;
    //     for(int j=0;j<i;j++){
    //         if(price[j]<=price[i]){
    //             count++;
    //         }
    //         else{
    //             count=1;
    //         }
    //     }
    //     ans.push_back(count);
    // }
    stack<pair<int,int>>s;
    for(int i=0;i<n;i++){
        int count=1;
        while(s.size() && s.top().first<=price[i]){
            count+=s.top().second;
            s.pop();
        }
        s.push({price[i],count});
        ans[i]=count;
    }
    return ans;
}
