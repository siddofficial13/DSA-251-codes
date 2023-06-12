#include <bits/stdc++.h>
void buildZ(vector<int> &z,string temp,int n){
    int l=0;
    int r=0;
    z[0]=0;
    for(int i=1;i<n;i++){
        if(i>r){
          l=i;
        r=i;
        
        while(r<n && temp[r-l]==temp[r]){
            r++;
        }
        z[i]=r-l;
        r--;
        }
        else{
            int k=i-l;
            if(z[k]<=r-i){
                z[i]=z[k];
            }
            else{
                l=i;
                while(r<n && temp[r-l]==temp[r]){
                    r++;
                }
                z[i]=r-l;
                r--;
            }
        }
        
    }
}
int zAlgorithm(string s, string p, int n, int m)
{
	// Write your code here
    int count = 0;
    
    string temp=p+"$"+s;
    int len=temp.size();
    vector<int>z(len);
    buildZ(z,temp,len);
    for(int i=0;i<len;i++){
        if(z[i]==p.size()){
            // index=i-p.size()-1;
            count++;
        }
    }
    return count;
    
}
