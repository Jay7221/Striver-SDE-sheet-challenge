#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

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
TreeNode<int>* util(TreeNode<int> *root){
    if(root == NULL){
        return root;
    }
    TreeNode<int> *left, *right, *leftEnd, *rightEnd;
    left = root -> left;
    right = root -> right;
    leftEnd = util(left);
    rightEnd = util(right);
    if(left != NULL){
        root -> right = left;
        leftEnd -> right = right;
    }
    if(rightEnd == NULL){
        if(leftEnd == NULL){
            return root;
        }
        return leftEnd;
    }
    return rightEnd;
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    util(root);
    return root;
}
