class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> large; 
    priority_queue<int> small;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(small.empty() || small.top()>num) small.push(num);
        else large.push(num);
        
        if(small.size()>large.size()+1){
            int val=small.top();
            large.push(val);
            small.pop();
        }
        else if(large.size()>small.size()+1){
            int val=large.top();
            small.push(val);
            large.pop();
        }
    }
    
    double findMedian() {
        if(small.size()>large.size()){
            return small.top();
        }
        if(large.size()>small.size()){
            return large.top();
        }
        return (large.top()+small.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
#include<bits/stdc++.h>
void findMedian(int *arr, int n)
{
    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<int>> mn;
    
    for(int i=0; i<n; i++){
        if(mx.size() == 0) mx.push(arr[i]);
        else if(arr[i] > mx.top()) mn.push(arr[i]);
        else mx.push(arr[i]);
        
        if(mx.size() - mn.size() == 2)
            mn.push(mx.top()), mx.pop();
        else if(mn.size() - mx.size() == 1)
            mx.push(mn.top()), mn.pop();
        
        if(mx.size() == mn.size())
            cout << (mx.top() + mn.top())/2 << " ";
        else cout << mx.top() << " ";  
    }
}
