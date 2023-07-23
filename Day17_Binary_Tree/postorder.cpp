#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> postorder;
    function<void(TreeNode*)> dfs;
    dfs = [&](TreeNode *root){
        if(root == NULL){
            return;
        }
        dfs(root -> left);
        dfs(root -> right);
        postorder.push_back(root -> data);
    };
    dfs(root);
    return postorder;
}
