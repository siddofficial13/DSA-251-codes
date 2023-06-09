class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n,vector<int>(n,INT_MAX));
        for(auto it: edges){
            distance[it[0]][it[1]]=it[2];
            distance[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++){
            distance[i][i]=0;
        }
        for(int k=0;k<n;k++) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(i!=k && j!=k && distance[i][k]!=INT_MAX && distance[k][j]!=INT_MAX) {
					distance[i][j]=min(distance[i][j],distance[i][k]+distance[k][j]);
				}
			}
		}
	}
    int countCity=n;
    int cityNumber=-1;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(i!=j && distance[i][j]<=distanceThreshold){
                count++;
            }
        }
        if(count<=countCity){
            countCity=count;
            cityNumber=i;
        }
    }
    return cityNumber;
    }
};
