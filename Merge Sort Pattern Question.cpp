class Solution {
public:
    long long merge(int lo, int mid,int hi,vector<int>& nums,int lower,int upper){
        long long ans =0;
        for(int i=lo;i<=mid;i++){
            int startIdx = lower_bound(nums.begin() + mid + 1, nums.begin() + hi + 1, lower - nums[i]) - nums.begin(); 
            int endIdx = upper_bound(nums.begin() + mid + 1, nums.begin() + hi + 1, upper - nums[i]) - nums.begin();
            ans += 1LL * (endIdx - startIdx);
        }
        int size = hi-lo+1;
        vector<int> temp(size, 0);
        int left = lo, right = mid+1, k=0;
        while(left<=mid && right<=hi){
            if(nums[left] < nums[right]){
                temp[k++] = nums[left++];
            }
            else{
                temp[k++] = nums[right++];
            }
        }
        while(left<=mid){
            temp[k++] = nums[left++]; 
        }
        while(right<=hi){
            temp[k++] = nums[right++]; 
        }
        int m=0;
        for(int i=lo; i<=hi; i++){
            nums[i] = temp[m++];
        }
        return ans;
    }
    long long mergeSort(int lo,int hi,vector<int>& nums,int lower,int upper){
        if(lo>=hi){
            return 0;
        }
        int mid = (lo+hi)/2;
        long long ans=0;
        ans+=mergeSort(lo,mid,nums,lower,upper);
        ans+=mergeSort(mid+1,hi,nums,lower,upper);
        ans+=merge(lo,mid,hi,nums,lower,upper);
        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        return mergeSort(0,nums.size()-1,nums,lower,upper);
    }
};`
