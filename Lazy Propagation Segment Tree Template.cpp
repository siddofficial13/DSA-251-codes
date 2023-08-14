#include <bits/stdc++.h>
using namespace std;

class SGTree{
public:
    vector<int> seg,lazy;
public:
    SGTree(int n) {
        seg.resize(4 * n + 1);
        lazy.resize(4*n+1);
    }
    void build(int ind, int low, int high, vector<int> &arr){
        if(low==high){
            seg[ind]=arr[low];
            return;
        }
        int mid  = (low+high)/2;
        build(2*ind +1,low,mid,arr);
        build(2*ind +2,mid+1,high,arr);
        seg[ind]=seg[2*ind +1]+seg[2*ind +2];
    }
    int query(int ind, int low, int high, int l ,int r){

        //update if any updates  are remaining
        if(lazy[ind]!=0){
            seg[ind]+=(high-low+1)*lazy[ind];
            //propagate the lazy update downwards
            //for the remaining of the nodes to get updated
            if(low!=high){ //condition to check for children
                lazy[2*ind +1]+=lazy[ind];
                lazy[2*ind +2]+=lazy[ind];
            }
            lazy[ind]=0;
        }
       //no overlap case
        if(high<l or r<low){
            return 0;
        }
        //complete overlap
        //[l low high r]
        if(low>=l && high<=r) return seg[ind];
        //partial overlap
        int mid = (low+high)/2;
        int left = query(2*ind +1,low,mid,l,r);
        int right = query(2*ind +2,mid+1,high,l,r);
        return left+right;
    }
    void update(int ind, int low, int high, int l, int r,int val){
       //update the previous remaining updates
       //propagate downwards
       if(lazy[ind]!=0){
           seg[ind]+=(high-low+1)*lazy[ind];
           //propagate the lazy update downwards
           //for the remaining of the nodes to get updated
           if(low!=high){ //condition to check for children
                lazy[2*ind +1]+=lazy[ind];
                lazy[2*ind +2]+=lazy[ind];
           }
           lazy[ind]=0;
       }
       //no overlap
       //we don't do anything and return
       //low high l r or l r low high
       if(high<l or r<low){
           return;
       }
       //complete overlap
       //l low high r
       if(low>=l && high<=r) {
           seg[ind]+=(high-low+1)*val;
           // if a leaf node, it will have childrens
           if(low!=high){
               lazy[2*ind+1] += val;
               lazy[2*ind+2] += val;
           }
           return;
       }
       //partial overlap case
       int mid  = (low+high)/2;
       update(2*ind+1,low,mid,l,r,val);
       update(2*ind +2,mid+1,high,l,r,val);
       seg[ind]=seg[2*ind+1]+seg[2*ind+2];

    }
};


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++)  cin>>arr[i];
    SGTree sgTree(n);
    sgTree.build(0,0,n-1,arr);
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int l,r;
            cin>>l>>r;
            cout<<sgTree.query(0,0,n-1,l,r)<<endl;
        }
        else{
          int l,r,val;
          cin>>l>>r>>val;
          sgTree.update(0,0,n-1,l,r,val);
        }
    }
    return 0;
}
