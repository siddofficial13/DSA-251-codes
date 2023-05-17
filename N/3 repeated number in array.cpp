#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int n =arr.size();
    int N = floor(n/3);
    map<int,int>mp;
	for(int i=0;i<n;i++){
		mp[arr[i]]++;
	}
    vector<int>res;
    for(auto itr: mp){
        if(itr.second>N){
            res.push_back(itr.first);
        }
    }
    return res;
}
