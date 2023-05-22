
#include<bits/stdc++.h>
long long int floorSqrt(long long int N)
{
    // Write your code here.
    // double ans  = sqrt(N);
    // return (long long)(ans);
  long long int lo=0;
  long long int hi=N;
  long long int ans=-1;
  long long int mid = lo +(hi-lo)/2;
  while(lo<=hi){
      long long int square = mid*mid;
      if(square==N)return mid;
      if(square<N){
          ans=mid;
          lo=mid+1;
      }
      else{
          hi=mid-1;
      }
      mid = lo +(hi-lo)/2;
  }
  return ans;
}
