#include<bits/stdc++.h>
int findAllSubarraysWithGivenSum(vector < int > & arr, int sum) {
    // Write Your Code Here
    int n = arr.size();
    unordered_map<int,int>mp;
    int count=0;
    int currsum=0;
    for(int i=0;i<n;i++){
        currsum+=arr[i];
        if(currsum==sum){
            count++;
        }
        if(mp.find(currsum-sum)!=mp.end()){
            count+=(mp[currsum-sum]);
        }
        mp[currsum]++;
    }
    return count;
}
