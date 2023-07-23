#include<bits/stdc++.h>
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

int maxPathSum(TreeNode<int> *root)
{
    function<int(TreeNode<int>*)> dfs;
    int ans = -(1e9 + 7);
    dfs = [&ans, &dfs](TreeNode<int> *root){
        if(root == NULL){
            return 0;
        }
        int left = dfs(root -> left);
        int right = dfs(root -> right);
        int cur = root -> data;
        ans = max({ans, cur + left + right, cur + max(left, right)});
        return (max(0, cur + max(left, right)));
    };
    dfs(root);
    return ans;

}
