#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
class Info{
    public:
        int maxi;
        int mini;
        bool isValid;
        int size;
    public:
        Info(){
            maxi = INT_MIN;
            mini = INT_MAX;
            isValid = true;
            size = 0;
        }
};



Info* solver(TreeNode<int>* root, int &ans){
    if(root == NULL){
        Info* node = new Info;
        return node;
    }

    Info* left = solver(root->left, ans);
    Info* right = solver(root->right, ans);

    Info *head = new Info;
    head->maxi = max(right->maxi, root->data);
    head->mini = min(left->mini, root->data);
    head->size = left->size + right->size + 1;

    if(left->isValid && right->isValid && (root->data > left->maxi && root->data < right->mini)){
        head->isValid = true;
    }
    else{
        head->isValid = false;
    }

    if(head->isValid) ans = max(ans, head->size);

    return head;
}


int largestBST(TreeNode<int>* root) 
{
    // Approach: Visite each node and check if it is a valid BST or not.
    // Also return all the necessary information as a data structure.
    // Time Complexity: O(N)
    // Space Complexity: O(Height)
    int maxAns = 0;
    Info* result = solver(root, maxAns);

    return maxAns;
}
