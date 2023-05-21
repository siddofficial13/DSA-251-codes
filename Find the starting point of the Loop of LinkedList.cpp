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

Node *firstNode(Node *head)
{
	//    Write your code here.
	//Basic Approach O(n) time and O(n) space
    //  unordered_set<Node *>st;
	//  while(head!=NULL){
	// 	 if(st.find(head) != st.end()){
	// 		 return head;
	// 	 }
	// 	 st.insert(head);
	// 	 head=head->next;
	//  }
	//  return NULL;
	//O(n) time complexity and O(1) space complexity approach   
	if(head ==NULL || head->next == NULL){
		return NULL;
	}
	Node* fast=head;
	Node* slow=head;
	Node* entry=head;
	while(fast->next!=NULL && fast->next->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(slow==fast){
			while(slow!=entry){
				slow=slow->next;
				entry=entry->next;
			}
			return slow;
		}
	}
	return NULL;
}
