long long connectRopes(int* arr, int n)
{
    // Your code goes here
    priority_queue<int,vector<int>,greater<int>>minHeap;
    // int n=arr.size();
    for(int i=0;i<n;i++){
        minHeap.push(arr[i]);
    }
    long long cost=0;
    while(minHeap.size()!=1){
        int x=minHeap.top();
        minHeap.pop();
        int y=minHeap.top();
        minHeap.pop();
        int sum=x+y;
        cost+=sum;
        minHeap.push(sum);
    }
    return cost;
}
