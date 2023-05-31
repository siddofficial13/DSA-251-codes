#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int>* insertionInBST(TreeNode<int>* root, int val)
{
    // Write your code here.
    if(root==NULL)return new TreeNode<int>(val);
        TreeNode<int> *curr=root;
        while(true){
            if(curr->val<=val){
                if(curr->right!=NULL){
                    curr=curr->right;
                }
                else{
                    curr->right=new TreeNode<int>(val);
                    break;
                }
            }
            else{
                if(curr->left!=NULL){
                    curr=curr->left;
                }
                else{
                    curr->left=new TreeNode<int>(val);
                    break;
                }
            }
        }
        return root;
}
