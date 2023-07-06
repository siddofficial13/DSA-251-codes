/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* f(vector<int> &tree,int i, int j){
        if(i>j) return NULL;
        int k = (i+j)/2;
        TreeNode * root = new TreeNode(tree[k]);
        root->left = f(tree,i,k-1);
        root->right = f(tree,k+1,j);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> tree;
        while(head!=NULL){
            tree.push_back(head->val);
            head=head->next;
        }
      TreeNode * head2 = f(tree,0,tree.size()-1);
      return head2;
    }
};
