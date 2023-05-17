#include <bits/stdc++.h> 
vector<int> separateNegativeAndPositive(vector<int> &arr){
    // Write your code here.
    //O(nlogn) approach
    // sort(nums.begin(),nums.end());
    // return nums;
    int i=0;
    int j=arr.size()-1;
    while(i<j){
        if(arr[i]<0 && arr[j]>0){
            i++;
            j--;
        }
        else if(arr[i]>=0 && arr[j]<0){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
        else if(arr[i]<0 && arr[j]<0){
            i++;
        }
        else {
            j--;
        }
    }
    return arr;

}
