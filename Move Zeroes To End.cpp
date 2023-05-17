void pushZerosAtEnd(vector<int> &arr) 
{
	// Write your code here.
	int n = arr.size();
	int index;
	int i=0;
	for(int j=0;j<n;j++){
		if(arr[j]!=0){
			if(arr[i]!=0){
				i++;
			}
			else{
				swap(arr[i],arr[j]);
				i++;
			}
		}
	}
}
