#include <bits/stdc++.h> 
int minimumOperations(string &a, string &b)
{
    //  Write your code here.
    int n1=a.size();
    int n2=b.size();
    if(n1!=n2){
        return -1;
    }
    int count=0;
    for(int i=0;i<n1/2;i++){
        unordered_map<char,int>mp;
        mp[a[i]]++;
        mp[b[i]]++;
        mp[a[n1-i-1]]++;
        mp[b[n2-i-1]]++;
        if(mp.size()==4){
            count+=2;
        }
        else if(mp.size()==3){
            count+=1+(a[i]==a[n1-i-1]);
        }
        else if(mp.size()==2){
            count+=(mp[a[i]]!=2);
        }


    }
    if(n1%2!=0 && a[n1/2]!=b[n1/2])count++;
    return count;
    
}
