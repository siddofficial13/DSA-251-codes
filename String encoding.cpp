#include <bits/stdc++.h> 
string encode(string &message)
{
    //   Write your code here.
    // map<char,int>mp;
    int n = message.size();
    // for(int i=0;i<n;i++){
    //     mp[message[i]]++;
    // }
    string ans ="";
    // for(auto itr: mp){
    //     ans=ans+itr.first;
    //     int a = itr.second;
    //     char c = a+'0';
    //     ans =ans+c;
    // }
    // return ans;
    for(int i=0;i<n;){
        int count=0;
        char temp =message[i];
        while(message[i]==temp){
            count++;
            i++;
        }
        ans=ans+temp;
        string c = to_string(count);
        ans=ans+c;
    }
    return ans;
}
