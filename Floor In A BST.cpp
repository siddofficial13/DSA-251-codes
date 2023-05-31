int floorInBST(TreeNode<int> * root, int key)
{
    // Write your code here.
     int floor=-1;
    while(root){
        if(root->val==key){
            floor=root->val;
            return floor;
        }
        if(key>root->val){
            floor=root->val;
            root=root->right;
        }
        else{
            // ceil=root->data;
            root=root->left;
        }
    }
    return floor;
}
