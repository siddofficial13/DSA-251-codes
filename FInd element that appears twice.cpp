int singleNonDuplicate(vector<int>& nums)
{
	// Write your code here
	//O(n) approach
	// int xorval=0;
	// for(int i=0;i<arr.size();i++){
	// 	xorval=xorval^arr[i];
	// }
	// return xorval;
	int n = nums.size();
	 int low = 0;
            int high = n - 2;
        
            while (low <= high) {
                int mid = (low + high) / 2;
                
                if (mid % 2 == 0) {
                    if (nums[mid] != nums[mid + 1]) 
                    //Checking whether we are in right half

                        high = mid - 1; //Shrinking the right half
                    else
                        low = mid + 1; //Shrinking the left half
                } else {

                    //Checking whether we are in right half
                    if (nums[mid] == nums[mid + 1]) 
                        high = mid - 1; //Shrinking the right half
                    else
                        low = mid + 1; //Shrinking the left half
                }
            }

            return nums[low];
	
}
