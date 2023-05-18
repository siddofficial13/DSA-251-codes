#include <bits/stdc++.h> 
int kadane(int a[], int n){
	int maxsum = INT_MIN;
	int currsum = 0;
	for(int i=0; i<n; i++){
		currsum += a[i];

		if(currsum < 0)
			currsum = 0;
		else if(currsum > maxsum)
			maxsum = currsum;
    }
    
    return (maxsum < 0) ? *max_element(a, a+n) : maxsum;
}
int maxSumRectangle(vector<vector<int>>& arr, int n, int m)
{
	int temp[n];
	int maxsum = INT_MIN, currsum;

	for(int cstart = 0; cstart < m; cstart++){
		memset(temp, 0, sizeof(temp));

                for (int cend = cstart; cend < m; cend++) {

                  for (int i = 0; i < n; i++)
                    temp[i] += arr[i][cend];

                  currsum = kadane(temp, n);
                  maxsum = max(currsum, maxsum);
                }
        }

        return maxsum;
}
