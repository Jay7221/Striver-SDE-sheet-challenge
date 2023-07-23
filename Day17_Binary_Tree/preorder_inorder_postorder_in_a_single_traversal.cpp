#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> traversals(3);
    function<void(BinaryTreeNode<int>*)> dfs;
    dfs = [&](BinaryTreeNode<int>* root){
        traversals[1].push_back(root -> data);
        if(root -> left != NULL){
            dfs(root -> left);
        }
        traversals[0].push_back(root -> data);
        if(root -> right != NULL){
            dfs(root -> right);
        }
        traversals[2].push_back(root -> data);
    };
    if(root != NULL){
        dfs(root);
    }
    return traversals;
}
