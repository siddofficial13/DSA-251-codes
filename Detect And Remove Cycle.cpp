/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/

Node *removeLoop(Node *head){
    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;
    

	// Loop Detection
    while(fast != NULL && slow != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
        if(slow == fast)
            break;
    }

	// Get Starting Node
    if(slow == fast){
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
    }
    // at this point slow, fast is at where 2 pointers are pointing

    while(slow->next != fast){
        slow = slow->next;
    }
    slow->next = NULL;
    return head;
    
}
