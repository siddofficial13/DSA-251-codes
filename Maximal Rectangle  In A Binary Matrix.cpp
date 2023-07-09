class Solution {
public:
       vector<int>LeftIndex(vector<int>& arr,int n)
      {
           vector<int>left;
           stack<pair<int,int>>s;
           int pseudoIndex=-1;
           for(int i=0;i<n;i++)
           {
               if(s.size()==0) left.push_back(pseudoIndex);
               else if(s.size()>0 && s.top().first<arr[i]) left.push_back(s.top().second);
               else if(s.size()>0 && s.top().first>=arr[i])
               {
                      while(s.size()>0 && s.top().first>=arr[i]) {s.pop();}
                      if(s.size()==0) left.push_back(pseudoIndex); 
                      else left.push_back(s.top().second);
               }
               s.push({arr[i],i});
        } 
           return left;
    }       
    vector<int>RightIndex(vector<int>& arr,int n)
    {
        vector<int>right;
        stack<pair<int,int>>s1;
        int pseudoIndex2=n;
        for(int i=n-1;i>=0;i--)
        {
            if(s1.size()==0) right.push_back(pseudoIndex2);
            else if(s1.size()>0 && s1.top().first<arr[i]) right.push_back(s1.top().second);
            else if(s1.size()>0 && s1.top().first>=arr[i])
            {
                while(s1.size()>0 && s1.top().first>=arr[i]) {s1.pop();}
                if(s1.size()==0)right.push_back(pseudoIndex2); 
                else right.push_back(s1.top().second);      
            }
            s1.push({arr[i],i});
        }
        reverse(right.begin(),right.end());
        return right;
    }
    int largestRectangleArea(vector<int>& arr) {
        
       int n = arr.size(); 
       vector<int>left  =LeftIndex(arr,n);
       vector<int>right =RightIndex(arr,n);
       int area=0;
       int mx=INT_MIN;
       for(int i=0;i<n;i++)
       {
           int width=right[i]-left[i]-1;
           area=arr[i]*width;
           mx=max(mx,area);
       }
       return mx;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> grid(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    grid[i][j]=1;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    grid[i][j]+=grid[i-1][j];
                }
            }
        }
        int maxm=INT_MIN;
        for(int i=0;i<n;i++){
            // for(int j=0;j<m;j++){
                maxm=max(maxm,largestRectangleArea(grid[i]));
            // }
        }
        return maxm;
    }
};
