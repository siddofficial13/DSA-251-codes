#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    int max_so_far =0;
    int max_ending_here =0;
    for(int i=0;i<n;i++){
        max_ending_here=max_ending_here+arr[i];
        max_so_far=max(max_so_far,max_ending_here);
        if(max_ending_here<0){
            max_ending_here=0;
        }
    }
    return max_so_far;
}
