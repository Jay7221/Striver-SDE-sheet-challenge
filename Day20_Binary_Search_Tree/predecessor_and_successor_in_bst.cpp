#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    bool found = false, foundNext = false;
    int prev = -1, next = -1;
    function<void(BinaryTreeNode<int>*)> dfs;
    dfs = [&](BinaryTreeNode<int> *root){
        if(!root){
            return;
        }
        dfs(root -> left);
        if(found && foundNext){
            return;
        }
        if(found){
            next = root -> data;
            foundNext = true;
            return;
        }
        if(root -> data == key){
            found = true;
        }else{
            prev = root -> data;
        }
        dfs(root -> right);
    };
    dfs(root);
    return make_pair(prev, next);
}

