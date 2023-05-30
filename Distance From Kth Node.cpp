vector<BinaryTreeNode<int>*> printNodesAtDistanceK(BinaryTreeNode<int>* root, BinaryTreeNode<int>* target, int K) {
    if(!root) {
        return {};
    }
    vector<BinaryTreeNode<int>*>v;
    queue<BinaryTreeNode<int>*>q;
    unordered_map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>parent;
    q.push(root);
    while(!q.empty()) {
        auto node=q.front();
        q.pop();
        if(node->left) {
            parent[node->left]=node;
            q.push(node->left);
        }
        if(node->right) {
            parent[node->right]=node;
            q.push(node->right);
        }
    }
    q.push(target);
    while(!q.empty()) {
        int n=q.size();
        while(n) {
            auto node=q.front();
            q.pop();
            if(K==0) {
                v.push_back(node);
            }
            if(parent.find(node)!=parent.end()) {
                q.push(parent[node]);
                if(parent[node]->left==node) {
                    parent[node]->left=NULL;
                }
                if(parent[node]->right==node) {
                    parent[node]->right=NULL;
                }
            }
            if(node->left) {
                q.push(node->left);
                parent.erase(node->left);
                node->left=NULL;
            }
            if(node->right) {
                q.push(node->right);
                parent.erase(node->right);
                node->right=NULL;
            }
            n--;
        }
        K--;
    }
    return v;
}
