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

int kthSmallest(TreeNode<int> *root, int k)
{
    int ans;
    function<void(TreeNode<int>*)> dfs;
    int cur = 0;
    dfs = [&](TreeNode<int> *root){
        if(!root){
            return;
        }
        dfs(root -> left);
        ++cur;
        if(cur > k){
            return;
        }
        if(cur == k){
            ans = root -> data;
            return;
        }
        dfs(root -> right);
    };
    dfs(root);
    return ans;
}
