#include <unordered_map>
#define ll long long int
ll solve(ll n)
{
    return n*(n-1)/2;
}
vector<long long> maxProductCount(vector<int> &arr, int n) {
    unordered_map <ll,ll> mpp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
            mpp[(ll)arr[i]*arr[j]]++;
    }
    ll product=0,c=0;
    for(auto it: mpp)
    {
        if(it.second>c){ product=it.first; c=it.second;}
        else if(it.second==c&&it.first<product) product=it.first;
    }
    return {product,solve(c)};
}
