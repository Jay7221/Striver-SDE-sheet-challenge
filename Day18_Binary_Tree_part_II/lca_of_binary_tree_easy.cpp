#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    int lca = -1;
    bool foundX = false, foundY = false;
    function<bool(TreeNode<int>*)> dfs;
    dfs = [&](TreeNode<int>* root){
        if(root == NULL){
            return false;
        }
        bool left = dfs(root -> left);
        bool right = dfs(root -> right);
        bool val = (root -> data == x) || (root -> data == y);
        if((left && right) || (left && val) || (val && right)){
            lca = root -> data;
        }
        return (left || right || val);
    };
    dfs(root);
    return lca;
}
