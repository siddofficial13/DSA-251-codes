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
    TreeNode* lca(TreeNode* node, int p, int q){
        if(node==NULL) return NULL;
        if(node->val == p || node->val == q) return node;
        TreeNode* left = lca(node->left,p,q);
        TreeNode* right = lca(node->right,p,q);

        if(left==NULL){
            return right;
        }
        else if(right==NULL){
            return left;
        }
        else{
            return node;
        }
        return node;
    }
    bool pathFunc(TreeNode* root,int target,string& path){
        if(root==NULL){
            return false;
        }
        if(root->val==target) return true;
        path.push_back('L');
        if(pathFunc(root->left,target,path)){
            return true;
        }
        path.pop_back();
        path.push_back('R');
         if(pathFunc(root->right,target,path)){
            return true;
        }
        path.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lowestCa = lca(root,startValue,destValue);
        string start_to_lca,lca_to_dest;
        pathFunc(lowestCa,startValue,start_to_lca);
        pathFunc(lowestCa,destValue,lca_to_dest);
        string ans="";
        ans.append(start_to_lca.length(),'U');
        ans.append(lca_to_dest);
        return ans;
    }
};
