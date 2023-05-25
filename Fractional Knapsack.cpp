#include <bits/stdc++.h> 
bool comp(pair<int,int>a,pair<int,int>b){
    double a1=(double)a.second/a.first;
    double a2=(double)b.second/b.first;
    return a1>a2;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(),items.end(),comp);
    double sum=0;
    for(int i=0;i<n;i++){
        if(items[i].first<=w){
            sum+=items[i].second;
            w-=items[i].first;
        }
        else{
          sum+=(items[i].second*((double)w/items[i].first));
          break;  
        }
    }
    return sum;

}
