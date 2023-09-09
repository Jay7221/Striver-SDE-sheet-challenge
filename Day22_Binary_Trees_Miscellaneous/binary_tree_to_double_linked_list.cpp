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

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root, BinaryTreeNode<int> *next = NULL) {
    if(!root){
        return root;
    }
    if(root -> right){
        root -> right = BTtoDLL(root -> right, next);
    }
    else{
        root -> right = next;
    }
    if(root -> left){
        return BTtoDLL(root -> left, root);
    }
    return root;
}
