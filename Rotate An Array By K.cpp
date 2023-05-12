#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

int main() {
    //Write your code here
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    int k;cin>>k;
    vector<int>temp(n,0);
    int i=0;
   for(int i=0;i<n;i++){
       temp[(n+i-k)%n]=v[i];
   }
    for(int j=0;j<n;j++){
        cout<<temp[j]<<" ";
    }

    return 0;
}
