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

Node* addNodes(Node* head, int n, int m) {
    // Write your code here.
	if(head==NULL || n==0 || m==0){
		return head;
	}
	Node *prev=NULL;
	Node *temp=head;
	while(temp!=NULL){
		for(int i=0;i<m && temp!=NULL ;i++){
			prev=temp;
			temp=temp->next;
		}
		if(temp==NULL){
			return head;
		}
		int sum=0;
		for(int i=0;i<n && temp!=NULL; i++ ){
           sum+=temp->data;
		   prev=temp;
		   temp=temp->next;
		}
		Node *dummy=new Node(sum);
		prev->next=dummy;
		dummy->next=temp;
	}
	return head;
}
