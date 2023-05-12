#include <bits/stdc++.h> 
int findSecondLargest(int n, vector<int> &arr)

{
    // Write your code here.
     sort(arr.begin(),arr.end());
     set<int>s;
     for(int i=0;i<n;i++){
         s.insert(arr[i]);
     }
     if(s.size()==1){
         return -1;
     }
     else{
         int maxm=arr[n-1];
         reverse(arr.begin(),arr.end());
         for(int i=1;i<n;i++){
             if(arr[i]<maxm){
                 maxm=arr[i];
                 break;
             }
         }
         return maxm;
     }
}
