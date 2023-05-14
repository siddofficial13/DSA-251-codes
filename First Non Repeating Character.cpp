#include <bits/stdc++.h> 
char firstNonRepeatingCharacter(string str) {
    
  // Write your code here
  map<char,int>mp;
   int n = str.size();
   for(int i=0;i<n;i++){
     mp[str[i]]++;
   }
  //  set<char>s;
  //  for(int i=0;i<n;i++){
  //    s.insert(str[i]);
  //  }
  char ans;
   bool flag=false;
   for(int i=0;i<n;i++){
     if(mp[str[i]]==1){
       flag=true;
       ans=str[i];
       break;
     }
   }
   if(flag){
     return ans;
   }
   else{
     return str[0];
   }

   
}
