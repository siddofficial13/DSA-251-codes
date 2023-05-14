void spiralPrint(int **matrix, int nRows, int nCols)
{
    //Write your code here
    int left=0;
    int right=nCols-1;
    int top=0;
    int bottom=nRows-1;
    while(top<=bottom && left<=right){
         for(int i=left;i<=right;i++){
             cout<<matrix[top][i]<<" ";
         }
         top++;
         for(int i=top;i<=bottom;i++){
             cout<<matrix[i][right]<<" ";
         }
         right--;
         if(top<=bottom){
             for(int i=right;i>=left;i--){
                 cout<<matrix[bottom][i]<<" ";
             }
             bottom--;
         }
         if(left<=right){
             for (int i = bottom; i >= top; i--) {
                   cout<<matrix[i][left]<<" ";
                }
                left++;
         }
    }
}
