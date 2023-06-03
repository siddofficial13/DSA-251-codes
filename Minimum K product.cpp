#include <bits/stdc++.h> 
const int M = (int)1e9 + 7;
int minProduct(vector<int> &arr, int n, int k) {
   nth_element(arr.begin(), arr.begin() + k, arr.end());
   int ans = 1;
   for (int i = 0; i < k; i++) ans = (ans * (long long)arr[i]) % M; 
   return ans;
}
