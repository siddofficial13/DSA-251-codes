#include <bits/stdc++.h>
bool isPossible(int *arr, int n) {
  bool flag1 = false;
  bool flag2 = true;
  for (int i = 0; i < n-1; i++){
      if(arr[i]>arr[i+1] && !flag1){
          if(arr[i+1]<arr[i-1] && i!=0){
              arr[i+1]=arr[i];
              flag1=true;
          }else{
             arr[i]=arr[i+1];
             flag1=true;
          }
         
      }
  }
  for(int i=0; i<n-1;i++){
      if(arr[i]>arr[i+1] && flag1){
          flag2=false;
          break;
      }
  }
  return flag2;
    //  Write your code here.
}
