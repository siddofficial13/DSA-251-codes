//Leetcode Code Link

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
          vector < vector < int >> result;
  if (root == NULL) {
    return result;
  }

  queue < TreeNode * > nodesQueue;
  nodesQueue.push(root);
  bool leftToRight = true;

  while (!nodesQueue.empty()) {
    int size = nodesQueue.size();
    vector < int > row(size);
    for (int i = 0; i < size; i++) {
      TreeNode * node = nodesQueue.front();
      nodesQueue.pop();

      // find position to fill node's value
      int index = (leftToRight) ? i : (size - 1 - i);

      row[index] = node -> val;
      if (node -> left) {
        nodesQueue.push(node -> left);
      }
      if (node -> right) {
        nodesQueue.push(node -> right);
      }
    }
    // after this level
    leftToRight = !leftToRight;
    result.push_back(row);
  }
  return result;
    }
};
//CodeStudio Code Link
#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root) {
    // Approach: Using a queue and temp vectors.
    vector<int> ans;
    if(root == NULL) return ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    bool flag = true;
    while(!q.empty()){
        int n = q.size();
        vector<int> temp(n);
        for(int i = 0; i < n; i++){
            BinaryTreeNode<int> *curr = q.front();
            q.pop();
            // Check
            if(flag)
                temp[i] = curr->data;
            else
                temp[n - i - 1] = curr->data;
            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
        }
        // update the ans
        for(auto it : temp){
            ans.push_back(it);
        }
        flag = !flag;
    }
}
