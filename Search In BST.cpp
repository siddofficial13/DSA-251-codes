 while(root!=NULL && root->val!=val){
            root=val<root->val?root->left:root->right;
        }
        return root;
