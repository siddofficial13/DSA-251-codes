#include <bits/stdc++.h> 
int subArrayCount(vector<int> &nums, int k) {
    // Write your code here. int n = nums.size();
        vector<int> sums(k, 0);
        int n = nums.size();
        sums[0]++;
        int cnt = 0;
        int currSum = 0;
        for(int i = 0; i<n; i++) {
            currSum = (currSum + nums[i]%k + k)%k;
            cnt += sums[currSum];
            sums[currSum]++;
        }
        return cnt;
    
}
