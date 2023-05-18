#include <bits/stdc++.h> 
bool binsearch(int sum, int start, int end, vector<int> &arr)
{
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == sum) {
            return true;
        }
        else if (arr[mid] > sum) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return false;
}
vector<int> findTriplets(vector<int> &arr, int n) 
{
    //Write your code here.
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(binsearch(arr[i]+arr[j], j, n-1, arr)){
                return {arr[i],arr[j],arr[i]+arr[j]};
            }
        }
    }
    return {};
    // reverse(arr.begin(),arr.end());
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n-1;j++){
    //         for(int k=j+1;k<n;k++){
    //             if(arr[j]+arr[k]==arr[i]){
    //                 return {arr[i],arr[j],arr[k]};
    //             }
    //         }
    //     }
    // }
    // return {};
}
