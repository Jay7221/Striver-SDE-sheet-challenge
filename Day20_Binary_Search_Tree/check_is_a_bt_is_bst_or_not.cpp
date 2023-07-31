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

bool validateBST(BinaryTreeNode<int> *root) {
    function<void(BinaryTreeNode<int>*)> preorder;
    bool ans = true;
    int cur = -(1e9 + 7);
    preorder = [&](BinaryTreeNode<int> *root){
        if(root == NULL){
            return;
        }
        preorder(root -> left);
        if(root -> data < cur){
            ans = false;
            return;
        }
        cur = root -> data;
        preorder(root -> right);
    };
    preorder(root);
    return ans;
}
