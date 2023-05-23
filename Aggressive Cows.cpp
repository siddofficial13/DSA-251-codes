#include<bits/stdc++.h>
bool isPossible(vector<int> a, int n, int cows, int minDist) {
      int cntCows = 1;
      int lastPlacedCow = a[0];
      for (int i = 1; i < n; i++) {
        if (a[i] - lastPlacedCow >= minDist) {
          cntCows++;
          lastPlacedCow = a[i];
        }
      }
      if (cntCows >= cows) return true;
      return false;
    }
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(),stalls.end());
    int maxm=stalls[stalls.size()-1]-stalls[0];
    int low=1;
    int high=maxm;
    while(low<=high){
        int mid = (low + high) >> 1;

        if (isPossible(stalls, stalls.size(), k, mid)) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
    }
    return high;

}
