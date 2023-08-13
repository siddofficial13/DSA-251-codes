#include <bits/stdc++.h>
using namespace std;

class SGTree{
public:
    vector<vector<int>>seg;
public:
    SGTree(int n) {
        seg.resize(4 * n + 1, vector<int>(3, 0)); // Initialize internal vectors
    }

    vector<int> merge(vector<int> &left,vector<int> &right){
        vector<int>v(3,0);
        v[2]=left[2]+right[2]+min(left[0],right[1]);
        v[0]=left[0]+right[0]-min(left[0],right[1]);
        v[1]=left[1]+right[1]-min(left[0],right[1]);
        return v;
    }
    void build(int ind, int low, int high, string &s){
        if(low==high){
            seg[ind][0]=s[low]=='(';
            seg[ind][1]=s[low]==')';
            seg[ind][2]=0;
            return;
        }
        int mid  = (low+high)/2;
        build(2*ind +1,low,mid,s);
        build(2*ind +2,mid+1,high,s);
        seg[ind]=merge(seg[2*ind +1],seg[2*ind +2]);
    }
    vector<int>query(int ind, int low, int high, int l ,int r){
//        vector<int> v(3,0);
        //no overflow
        //l r low high or low high l r
        if(r<low || high<l) return {0,0,0};
        //complete overflow
        //[l low high r]
        if(low>=l && high<=r) return seg[ind];
        int mid = (low+high)/2;
        vector<int> left = query(2*ind +1,low,mid,l,r);
        vector<int> right = query(2*ind +2,mid+1,high,l,r);
        return merge(left,right);
    }
//    void update(int ind, int low, int high, int i, int val,int orr){
//        if(low==high){
//            seg[ind]=val;
//            return;
//        }
//        int mid = (low+high)/2;
//        if(i<=mid) update(2*ind +1,low,mid,i,val,!orr);
//        else update(2*ind +2,mid+1,high, i,val,!orr);
//        if(orr) seg[ind] = seg[2*ind +1] | seg[2*ind +2];
//        else seg[ind] = seg[2*ind +1] ^ seg[2*ind +2];
//    }
};


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n=s.size();
    SGTree sgTree(n);
    sgTree.build(0,0,n-1,s);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        cout<<sgTree.query(0,0,n-1,l,r)[2]*2<<endl;
    }

    return 0;
}
