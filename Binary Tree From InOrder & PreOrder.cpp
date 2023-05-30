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
    TreeNode * buildTree(vector<int> &preorder,vector<int> &inorder,int pm,int pn,int im,int in,map<int,int> &mp){
        if(pm>pn || im>in){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[pm]);
        int inRoot=mp[root->val];
        int numsLeft=inRoot-im;
        root->left = buildTree(preorder,inorder,pm+1,pm+numsLeft,im,inRoot-1,mp);
        root->right =buildTree(preorder,inorder,pm+1+numsLeft,pn,inRoot+1,in,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
           mp[inorder[i]]=i;
        }
        TreeNode *root = buildTree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,mp);
        return root;
    }
};
