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
    while((root -> data) != key){
        if(root -> data > key){
            next = root -> data;
            root = root -> left;
        }else{
            prev = root -> data;
            root = root -> right;
        }
    }
    BinaryTreeNode<int> *l = root -> left, *r = root -> right;
    if(l != NULL){
        while(l -> right){
            l = l -> right;
        }
        prev = l -> data;
    }
    if(r){
        while(r -> left){
            r = r -> left;
        }
        next = r -> data;
    }
    return make_pair(prev, next);
}

