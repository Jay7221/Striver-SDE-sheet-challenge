#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    if(P -> data > Q -> data){
        swap(P, Q);
    }
    TreeNode<int> *lca = root;
    while(true){
        if((lca -> data < (P -> data))){
            lca = lca -> right;
        }else if((lca -> data > (Q -> data))){
            lca = lca -> left;
        }else{
            break;
        }
    }
    return lca;
}

