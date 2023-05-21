class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& arr) {
        int n =arr.size();
        int count=0;
        int maxm=0;
        for(int i=0;i<n-1;i++){
            if(arr[i]==0){
                count=0;
                continue;
            }
            if(arr[i]==1){
                count++;
                // if(arr[i+1]==1){
                //     count++;
                //     i++;
                // }
            }
            maxm=max(count,maxm);
        }
        count+=arr[n-1];
        maxm=max(count,maxm);
        return maxm;
    }
    
};
