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

Node* pairsSwap(Node *head)
{
    //  Write your code here.
    if(head == NULL){
            return head;
        }
        Node *dummy = new Node(0);
        dummy->next= head;
        Node *cur =dummy, *nex=dummy, *pre = dummy;
        int length=0;
        while(cur->next!=NULL){
            cur=cur->next;
            length++;
        }
        while(length>=2){
            cur=pre->next;
            nex=cur->next;
            for(int i=1;i<2;i++){
                cur->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=cur->next;
            }
            pre=cur;
            length=length-2;
        }
        return dummy->next;
}
