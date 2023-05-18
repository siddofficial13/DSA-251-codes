#include<bits/stdc++.h>
#define ll long long
string multiplyStrings(string a , string b ){
    //Write your code here
    //using library functions
    //  ll num1 = stoll(a);
    //  ll num2= stoll(b);
    //  ll prod=(ll)(num1*num2);
    //  string ans = to_string(prod);
    //  return ans;
    int n1=a.size();
    int n2=b.size();
    if(n1==0 || n2==0){
        return "0";
    }
    vector<int> v(n1+n2,0);
    int i_n1=0;
    int i_n2=0;
    for(int i=n1-1;i>=0;i--){
        int carry=0;
        int num1=a[i]-'0';
        i_n2=0;
        for (int j = n2 - 1; j >= 0; j--) {
          int num2 = b[j] - '0';
          int sum = (num1 * num2) + v[i_n1 + i_n2] + carry;
          carry = sum / 10;
          v[i_n1 + i_n2] = sum % 10;
          i_n2++;
        }
        if (carry > 0)
    {
        v[i_n1+i_n2]+=carry;
        
    }
    i_n1++;
    }
    int i= v.size()-1;
    while(i>=0 && v[i]==0){
        i--;
    }
    if(i==-1){
        return "0";
    }
    string ans="";
    while(i>=0){
      ans+=to_string(v[i--]);
    }
    return ans;
}
