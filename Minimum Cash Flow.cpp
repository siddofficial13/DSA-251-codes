#include <bits/stdc++.h> 
int minCashFlow(vector<vector<int>>& money, int n)
{
  // Write your code here.
   vector<int> v(n,0); // of n friends

   for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
  if(i==j){
               continue; //simple
           }
           else{
               v[i] -= money[i][j];  // money sent
               v[j] += money[i][j]; // money recieved
           }
       }
   }
   
   int ans = 0;
   for(int i=0;i<n;i++){
       if(v[i]>0){  // calculate either net credit or net debit
           ans += v[i];
       }
   }

   return ans;   //simple
}
