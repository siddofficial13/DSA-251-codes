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

Node * segregateOddEven (Node * head)
{
	// Write your code here.
	//Basic intution is that just traverse the whole ll and as soon as you encounter a even node then push it to the tail;

	if(head==NULL){
		return head;
	}
	Node *tail=head;
	int c=1;
	while(tail->next!=NULL){//finding the tail and the length of the linked list
		c++;
		tail=tail->next;
	}
	Node *dummy = new Node(-1);//to avoid storing previous
	dummy->next=head;
	Node *temp=dummy;//iterator 
	while(c>0){
		c--;
		if(temp->next->data%2==0){//even data node
			Node *nex=temp->next->next;//store next of it
			temp->next->next=NULL;
			tail->next=temp->next;//insert at tail
			tail = tail->next;//update tail
			temp->next=nex;//break connection
		}
		else{
			temp=temp->next;//for odd keep moving the head 
		}
	}
	return dummy->next;// return head of the formed linked list
}
