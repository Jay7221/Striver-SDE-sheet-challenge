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
    int heightLCA = -1;
    int lca = -1;
    bool foundX = false, foundY = false;
    function<void(TreeNode<int>*, int)> dfs;
    dfs = [&](TreeNode<int>* root, int height){
        if(root == NULL){
            return;
        }
        dfs(root -> left, height + 1);
        
        if(root -> data == x){
            foundX = true;
        }
        if(root -> data == y){
            foundY = true;
        }
        if(((foundX || foundY) && !(foundX && foundY)) || (root -> data == x) || (root -> data == y)){
            if((heightLCA == -1) || (heightLCA > height)){
                heightLCA = height;
                lca = root -> data;
            }   
        }

        dfs(root -> right, height + 1);
    };
    dfs(root, 0);
    return lca;
}
