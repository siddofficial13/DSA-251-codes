#include <bits/stdc++.h> 
vector<vector<int>> sumOfKxKMatrices(vector<vector<int>> &arr, int k){

	
    vector<vector<int>> ans;
    int n=arr.size();
    int sum=0,i,j;
    //step 1
    for(i=0;i<k;i++)
    {
        for(j=0;j<k;j++)
            sum+=arr[i][j];
    }
    
    int ro=i;
    do
    {
        vector<int> temp;
        temp.push_back(sum);
        int tempsum=sum;
        //step 2,3
        for(int c=j;c<n;c++)
        {
            int r=0;
            while(r<k)
            {
                tempsum=tempsum+arr[ro-i+r][c]-arr[ro-i+r][c-j];
                r+=1;
            }
            temp.push_back(tempsum);
        }
        ans.push_back(temp);
        
        if(ro<n)
        {
        //step 4
            int p=0;
             while(p<k)
             {
                 sum=sum+arr[ro][p]-arr[ro-i][p];
                 p+=1;
             }
             ro+=1;
        }
        else
            break;
    }while(true);
    
    return ans;
}
