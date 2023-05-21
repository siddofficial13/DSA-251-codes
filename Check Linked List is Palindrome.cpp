#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
LinkedListNode<int> *reverse(LinkedListNode<int> *ptr){
    LinkedListNode<int> *pre = NULL;
    LinkedListNode<int> *nex = NULL;
    while(ptr!=NULL){
        nex = ptr->next;
        ptr->next = pre;
        pre = ptr;
        ptr = nex;
    }
    return pre;
}
bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    //brute force approach
    // vector<int>arr;
    // while(head!=NULL){
    //     arr.push_back(head->data);
    //     head=head->next;
    // }
    // for(int i=0;i<arr.size()/2;i++){
    //     if(arr[i] != arr[arr.size()-i-1]) return false;
    // }
    // return true;
       if(head==NULL || head->next==NULL){
           return true;
       }
       LinkedListNode<int> *slow=head;
       LinkedListNode<int> *fast=head;
       while(fast->next!=NULL && fast->next->next!=NULL){
           slow = slow->next;
           fast = fast->next->next;
       }
       slow->next = reverse(slow->next);
       slow = slow->next;
       LinkedListNode<int>* dummy = head;
        
    while(slow!=NULL) {
        if(dummy->data != slow->data) return false;
        dummy = dummy->next;
        slow = slow->next;
    }
    return true;

}
