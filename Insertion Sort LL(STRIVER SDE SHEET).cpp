#include <bits/stdc++.h> 
/****************************************************************
    Following is the Linked List node structure

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

Node* insertionSortLL(Node *head)
{
    // Write your code here.
    Node *dummy=head;
    Node *temp=head->next;
    dummy->next=NULL;
    while(temp!=NULL){
        Node *nex=temp->next;
        if(dummy->data > temp->data){
            Node *n =temp;
            n->next = dummy;
            dummy = n;
        }
        else{
            Node *prev = NULL;
            Node *j = dummy;
            while(j!=NULL && j->data <= temp->data){
                prev = j;
                j = j->next;
            }
            Node *n=temp;
            prev->next=n;
            n->next=j;
        }
        temp=nex;
    }
    return dummy;
}
