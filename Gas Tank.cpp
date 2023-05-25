
#include<bits/stdc++.h>

int minimumStartingIndex(vector<int> &gas, vector<int> &cost, int n) 
{
    int totalGas=0,totalCost=0;
    for(int i=0;i<n;i++) {
        totalGas+=gas[i];
        totalCost+=cost[i];
    }
    if(totalGas<totalCost) {
        return -1;
    }
    int fuel=0,start=0;
    for(int i=0;i<n;i++) {
        fuel+=gas[i];
        fuel-=cost[i];
        if(fuel<0) {
            fuel=0;
            start=i+1;
        }
    }
    return start;
}
