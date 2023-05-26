#include <bits/stdc++.h> 
// Stack class.
class Stack {
    private:
    int *arr;
    int to;
    int max_size;
    
public:
    
    Stack(int capacity) {
        // Write your code here.
        arr=new int[capacity];
        to=-1;
        max_size=capacity;
    }

    void push(int num) {
        // Write your code here.
        if(to+1!=max_size){
            to++;
            arr[to]=num;
        }
    }

    int pop() {
        // Write your code here.
        if(to!=-1){
            int ans=arr[to];
            to--;
            return ans;
        }
        return -1;
    }
    
    int top() {
        // Write your code here.
        if(to!=-1){
            return arr[to];
        }
        return -1;
    }
    
    int isEmpty() {
        // Write your code here.
        return (to==-1)?(1):(0);
    }
    
    int isFull() {
        // Write your code here.
        return (to==max_size-1)?(1):(0);
    }
    
};
