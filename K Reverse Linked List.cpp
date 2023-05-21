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

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
    stack<int>s;
    Node* ptr=head;
    Node* dummy=new Node(-1);
    Node* temp=dummy;
    for(int i=0;i<n;i++)
    {
        while(b[i]!=0 && ptr!=NULL)
        {
           s.push(ptr->data);
           ptr=ptr->next;
           b[i]--;
        }
        while(!s.empty())
        {
           Node* x=new Node(s.top());
           s.pop();
           temp->next=x;
           temp=temp->next;
        }
    }
    while(ptr!=NULL
    {
        temp->next=ptr;
        ptr=ptr->next;
        temp=temp->next;
    }
    return dummy->next;
}
