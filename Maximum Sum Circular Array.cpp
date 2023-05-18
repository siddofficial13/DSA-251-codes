int maxSubarraySum(vector<int> &arr, int n) {
	// Write your code here.
	if (n==1){
		return arr[0];

	}
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
	}
	int curr_sum=arr[0];
	int max_so_far=arr[0];
	int curr_min=arr[0];
	int min_so_far=arr[0];
	for(int i=1;i<n;i++){
		curr_sum=max(curr_sum+arr[i],arr[i]);
		max_so_far=max(max_so_far,curr_sum);
        curr_min=min(curr_min+arr[i],arr[i]);
		min_so_far=min(min_so_far,curr_min);
	}
	if(min_so_far==sum){
		return max_so_far;
	}
	return max(max_so_far,sum-min_so_far);
}
