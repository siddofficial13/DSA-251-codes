int maxArea(vector<int>& height) {
    // Write your code here.
    int n = height.size();
    int i=0;
    int j=n-1;
    int maxm=0;
    while(i<j){
        maxm=max(maxm,((j-i)*min(height[i],height[j])));
        if(height[i]<height[j]){
            i++;
        }
        else{
            j--;
        }
    }
    return maxm;
}
