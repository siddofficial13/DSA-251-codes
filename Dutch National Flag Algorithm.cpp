#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
   //Normal sorting code
   // sort(arr,arr+n);
   //Normal count approach
   // int count0=0;
   // int count1=0;
   // for(int i=0;i<n;i++){
   //    if(arr[i]==0){
   //       count0++;
   //    }
   //    else if(arr[i]==1){
   //       count1++;
   //    }
   // }
   // int count2=n-count1-count0;
   // int i=0;
   // while(count0--){
   //    arr[i]=0;
   //    i++;
   // }
   // while(count1--){
   //    arr[i]=1;
   //    i++;
   // }
   // while(count2--){
   //    arr[i]=2;
   //    i++;
   // }
   //Dutch National Flag Algorithm 
   int lo = 0;
    int hi = n - 1;
    int mid = 0;
  
    // Iterate till all the elements
    // are sorted
    while (mid <= hi) {
        switch (arr[mid]) {
  
        // If the element is 0
        case 0:
            swap(arr[lo++], arr[mid++]);
            break;
  
        // If the element is 1 .
        case 1:
            mid++;
            break;
  
        // If the element is 2
        case 2:
            swap(arr[mid], arr[hi--]);
            break;
        }
    }
}
