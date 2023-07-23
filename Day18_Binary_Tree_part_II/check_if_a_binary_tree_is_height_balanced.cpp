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

bool isBalancedBT(BinaryTreeNode<int>* root) {
    bool isBalanced = true;
    function<int(BinaryTreeNode<int>*)> height;
    height = [&](BinaryTreeNode<int>* root){
        if(root == NULL){
            return 0;
        }
        int h_left = height(root -> left);
        int h_right = height(root -> right);
        if(abs(h_left - h_right) > 1){
            isBalanced = false;
        }
        return (1 + max(h_left, h_right));
    };
    height(root);
    return isBalanced;
}
