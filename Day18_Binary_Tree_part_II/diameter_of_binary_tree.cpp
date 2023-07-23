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

int diameterOfBinaryTree(TreeNode<int> *root)
{
    int diameter = 0;
    function<int(TreeNode<int>*)> height;
    height = [&](TreeNode<int>* root){
        if(root == NULL){
            return 0;
        }
        int h_left = height(root -> left);
        int h_rigth = height(root -> right);
        diameter = max(diameter, h_left + h_rigth);
        return (1 + max(h_left, h_rigth));
    };
    height(root);
    return diameter;
}
