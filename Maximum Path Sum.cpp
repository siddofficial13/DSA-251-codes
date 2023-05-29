//codestudio code
#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
typedef long long ll;
ll helper(TreeNode<int> *root,ll &ans,ll &leaf) {
    if(!root) {
        return 0;
    }
    if(!root->left && !root->right) {
        leaf++;
    }
    ll l=helper(root->left,ans,leaf);
    ll r=helper(root->right,ans,leaf);
    ans=max(ans,l+root->val+r);
    return root->val+max(l,r);
}
ll findMaxSumPath(TreeNode<int> *root) {
    if(!root) {
        return -1;
    }
    ll ans=INT_MIN,leaf=0;
    helper(root,ans,leaf);
    return leaf>1?ans:-1;
}

//leetcode code easier to understand
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
    int maxPathDown(TreeNode *root, int &maxm){
        if(root==NULL)return 0;
        int left=max(0,maxPathDown(root->left,maxm));
        int right=max(0,maxPathDown(root->right,maxm));
        maxm=max(maxm,left+right+root->val);
        return max(left,right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxm=INT_MIN;
        maxPathDown(root,maxm);
        return maxm;
    }
};
