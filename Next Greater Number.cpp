#include<bits/stdc++.h>
string nextGreater(string S) {
	// Write your code here.
	int n = S.size();
	bool flag=false;
	for(int i=n-1;i>=1;i--){
      if(S[i]>S[i-1]){
		  sort(S.begin()+i,S.end());
		  int j=i;
		  while(S[j]<=S[i-1] && j<n){
			  j++;
		  }
		  swap(S[j],S[i-1]);
		  return S;
      }
	   else {
        continue;
      }
        } 
        return "-1";
}
