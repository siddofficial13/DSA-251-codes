#include <bits/stdc++.h> 

// Use this class to implement  the following operation
/* 
    class priQueue{
        int *arr;
        int size;

        priQueue(){
            arr=new int[1000];
            size=-1;
        }

        void push(int x);
        void pop();
        int getMaxElement();
        bool isempty();
    };
*/

    // Function to perform push operation
    void priQueue :: push(int data){
        if((size+1)<1000){
            size++;
            arr[size]=data;
            int i=size;
            while(i>0){
                if(arr[i]>arr[(i-1)/2]){
                    swap(arr[i],arr[(i-1)/2]);
                    i=(i-1)/2;
                }
                else{
                    break;
                }
            }
        }

        // Write the code here.
    } 

    // Function to pop operation
    void priQueue :: pop(){
        if(size==0){
            size--;
        }
        if(size>-1){
            swap(arr[0],arr[size]);
            //Heapify
            int i=0;
            while(i<size){
                int largest=i;
                int left=2*i+1;
                int right=2*i+2;
                if(left<size && arr[largest]<arr[left]){
                    largest=left;
                }
                if(right<size && arr[largest]<arr[right]){
                    largest=right;
                }
                if(largest!=i){
                    swap(arr[largest],arr[i]);
                }
                else{
                    break;
                }
                i=largest;
            }
            size--;
        }
        // Write the code here.
    }

    int priQueue :: getMaxElement(){
        if(size==-1)return size;
        return arr[0];
        // Write the code here.
    }


    bool priQueue :: isempty(){
          return size==-1;
        // Write the code here.
    }
