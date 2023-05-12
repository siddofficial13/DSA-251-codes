#include <bits/stdc++.h> 
int findEquilibriumIndex(vector<int> &arr) {
    // Write your code here.
    int n =arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    int sum2=0;
    bool flag=false;
    int ind;
    for(int i=0;i<n;i++){
        if(sum2==sum-sum2-arr[i]){
            ind=i;
            flag=true;
            break;
        }
        sum2+=arr[i];
    }
    if(flag){
        return ind;
    }
    else{
        return -1;
    }
}
