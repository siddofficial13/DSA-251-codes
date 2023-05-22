#include <bits/stdc++.h> 
int findKthElement(vector<int> &arr1, vector<int> &arr2, int k){
    // Write your code here.
    //O(n) approach
   int i=0;
   int j=0;
   int n1=arr1.size();
   int n2=arr2.size();
   int c=0;
   int ans;
   while(c<k){
       if(i!=n1 && j!=n2 && arr1[i]<arr2[j]){
          ans=arr1[i];
          i++;
       }
       else if(i!=n1 && j!=n2 && arr1[i]>arr2[j]){
           ans=arr2[j];
           j++;
       }
       else if(i!=n1 && j!=n2 && arr1[i]==arr2[j]){
           ans=arr2[j];
           j++;
       }
       else if(i==n1){
            ans=arr2[j];
           j++;
       }
       else if(j==n2){
            ans=arr1[i];
          i++;
       }
       c++;
   }
   return ans;

}
