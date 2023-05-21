#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

       class Node 
        { 
        public:
            int data;
            Node *next;
            Node(int data) 
            {
               this->data = data;
              this->next = NULL;
            }
        };

*****************************************************************/

Node *findMiddle(Node *head) {
    // Write your code here
    //Naive Approach 
    // Node *temp=head;
    // int count=0;
    // while(temp->next!=NULL){
    //    temp=temp->next;
    //    count++;
    // }
    // if(count%2){
    //     count=(count/2)+1;
    // }
    // else{
    //     count=(count/2);
    // }
    // Node *dummy=head;
    // for(int i=0;i<count;i++){
    //    dummy=dummy->next;
    // }
    // return dummy;
    Node*slow=head,*fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
