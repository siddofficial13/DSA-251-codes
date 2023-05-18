#include<bits/stdc++.h>

long long kadane(vector<int> &arr, int n, int k) {
    long long maxsum = INT_MIN, currsum = 0;
    for(int i=0; i<n*k;i++){
        currsum+=arr[i%n];
        maxsum=max(maxsum,currsum);
        if (currsum<0)
            currsum = 0;
    }
    return maxsum;
}

long long maxSubSumKConcat(vector<int> &arr, int n, int k){
  // 3 cases:
  // case 1: k = 1, return kadane(arr, n, 1);
  // case 2: k > 1, total sum > 0, return kadane(arr, n, 2) + (k - 2) * total
  // sum
  // case 3: k > 1, total sum < 0, return kadane(arr, n, 2)
  long long total=0;
  total=accumulate(arr.begin(),arr.end(),0);
  if(k==1){
     return kadane(arr, n, 1);
  }
  else if(total > 0){
     return kadane(arr, n, 2) + total*(k - 2);
  }
  else{
     return kadane(arr, n, 2);
  }
}
