#include <bits/stdc++.h> 
void selectionSort(vector<int>& arr, int n)
{   
    // Write your code here.
    int i,j,minm;
    for(i=0;i<n-1;i++){
        minm=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[minm]){
                minm=j;
            }
          
        }
        if(minm!=i){
            swap(arr[minm],arr[i]);
        }
    }
}
