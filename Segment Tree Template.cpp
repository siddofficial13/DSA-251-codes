#include <bits/stdc++.h>
using namespace std;

class SGTree{
    vector<int>seg;
public:
    SGTree(int n){
        seg.resize(4*n +1);
    }
    void build(int ind, int low, int high, vector<int> &arr){
        if(low==high){
            seg[ind]=arr[low];
            return;
        }
        int mid  = (low+high)/2;
        build(2*ind +1,low,mid,arr);
        build(2*ind +2,mid+1,high,arr);
        seg[ind]=min(seg[2*ind +1],seg[2*ind +2]);
    }
    int query(int ind, int low, int high, int l ,int r){
        //no overflow
        //l r low high or low high l r
        if(r<low || high<l) return INT_MAX;
        //complete overflow
        //[l low high r]
        if(low>=l && high<=r) return seg[ind];
        int mid = (low+high)/2;
        int left = query(2*ind +1,low,mid,l,r);
        int right = query(2*ind +2,mid+1,high,l,r);
        return min(left,right);
    }
    void update(int ind, int low, int high, int i, int val){
        if(low==high){
            seg[ind]=val;
            return;
        }
        int mid = (low+high)/2;
        if(i<=mid) update(2*ind +1,low,mid,i,val);
        else update(2*ind +2,mid+1,high, i,val);
        seg[ind]=min(seg[2*ind +1],seg[2*ind +2]);
    }
};


int main() {

    int n1;
    cin>>n1;
    vector<int> arr;
    for(int i=0;i<n1;i++){
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    SGTree sg1(n1);
    sg1.build(0,0,n1-1,arr);
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int l,r;
            cin>>l>>r;
            cout<<sg1.query(0,0,n1-1,l,r)<<endl;
        }
        else{
            int ind,val;
            cin>>ind>>val;
            sg1.update(0,0,n1-1,ind,val);

        }

    }
    return 0;
}
