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
void util(TreeNode<int> *root, TreeNode<int>* &prev){
    if(root == NULL){
        return;
    }
    util(root -> right, prev);
    util(root -> left, prev);
    root -> right = prev;
    root -> left = NULL;
    prev = root;
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *prev = NULL;
    util(root, prev);
    return root;
}
