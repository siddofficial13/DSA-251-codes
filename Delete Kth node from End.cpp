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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */Leetcode Solution
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
   ListNode * start = new ListNode();
        start -> next = head;
        ListNode* fast = start;
        ListNode* slow = start;     

        for(int i = 1; i <= n; ++i)
            fast = fast->next;
    
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return start->next;;
    }
};
*****************************************************************/

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    // Write your code here.
 if(head==NULL)return head;
   if(K==0)return head;
   LinkedListNode<int>* p=head;
   LinkedListNode<int>* q=head;
   LinkedListNode<int>* r=NULL;
   for(int i=1;i<=K;i++){
       p=p->next;
   } 
while(p){
r=q;
    p=p->next;
    q=q->next;
}
if(r==NULL)return head->next;
r->next=q->next;
return head;

}
