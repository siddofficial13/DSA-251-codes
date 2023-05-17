#include<bits/stdc++.h>
char kThCharaterOfDecryptedString(string s, long long k)
{
    k=k-1;
     long long n = s.size();
     long long i=0;
     while(i<n) {
         string currstring="";
         string currnum="";
        long long temp=0;
        long long l =i;
        long long r = i;
        while(i<n && s[i]>='a'&& s[i]<='z'){
            currstring+=s[i];
            i++;
        }
        while(i<n && s[i]>='0' && s[i]<='9'){
            currnum+=s[i];
            i++;
        }
        temp=(stoll(currnum));//to convert string to long long
        if (currstring.size() * temp > k) {
          return currstring[k % (currstring.size())];
        } else
          k -= (currstring.size() * temp);
        }
        return '-';
     
    //  Write your code here.
}
